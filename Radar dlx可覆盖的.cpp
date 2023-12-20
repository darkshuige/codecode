#include<bits/stdc++.h>
#define esp 1e-7
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int mxn = 55;
const int mxnode = 3000;
int n, m, k;
double dis[mxn][mxn];
pair<double, double> city[mxn], rada[mxn];
struct DLX
{
    int U[mxnode], D[mxnode], R[mxnode], L[mxnode];
    int Col[mxnode], Row[mxnode];
    int H[mxnode], S[mxnode];
    int ans, ansd[mxn];
    int size, n;
    int vis[mxn];
    void init(int _n)
    {
        n = _n;
        for(int i=0;i<=n;i++)
        {
            L[i] = i - 1;
            R[i] = i + 1;
            U[i] = D[i] = i;
        }
        R[n] = 0, L[0] = n, size = n;
        memset(H, -1, sizeof(H));
        memset(S,  0, sizeof(S));
    }
    void link(int r, int c)
    {
        Col[++ size] = c;
        Row[size] = r;
        S[c] ++;
        U[size] = U[c];
        D[size] = c;
        D[U[c]] = size;
        U[c] = size;
        if(H[r] == -1)
            H[r] = L[size] = R[size] = size;
        else
        {
            L[size] = size - 1;
            R[size] = H[r];
            R[L[size]] = size;
            L[H[r]] = size;
        }
    }
    void remove(int c)
    {
        for(int i = D[c]; i != c; i = D[i])
            L[R[i]] = L[i], R[L[i]] = R[i];
    }
    void resume(int c)
    {
        for(int i = U[c]; i != c; i = U[i])
            L[R[i]] = i, R[L[i]] = i;
    }
    int h()            //类似与A* 算法中的 h估值函数，表示从当前状态到结束状态至少还需要递归多少层；
    {
        memset(vis, 0, sizeof(vis));
        int sum = 0;
        for(int i = R[0]; i; i = R[i])
        {
            if(vis[i]) continue;
            vis[i] = 1;
            sum ++;
            for(int j = D[i]; j != i; j = D[j])
                for(int k = R[j]; k != j; k = R[k])
                    vis[Col[k]] = 1;
        }
        return sum;
    }
    int dance(int dep)
	{ //选取了d行 当前深度, limit 限制不能超过这个范围
        /*重复覆盖
        1、如果矩阵为空，得到结果，返回
        2、从矩阵中选择一列，以选取最少元素的列为优化方式
        3、删除该列及其覆盖的行
        4、对该列的每一行元素：删除一行及其覆盖的列，
        5、进行下一层搜索，如果成功则返回
        6、恢复现场，跳至4
        7、恢复所选择行
        */
        if(dep + h() > k) return 0;
        if(R[0] == 0)
		{//全部覆盖了
        //全覆盖了之后的操作
			return dep<=k;
        }
        int c = R[0];//表头结点指向的第一个列
        for(int i = R[0]; i != 0; i = R[i])//枚举列头指针
            if(S[i]<S[c])//找到列中元素个数最少的
                c = i;
        //remove(c);//将该列删去(精确覆盖)
        for(int i = D[c]; i != c; i = D[i]){//枚举该列的元素
            remove(i);//新增(重复覆盖)
            for(int j = R[i]; j != i; j = R[j]) remove(j);//remove(Col[j])(精确覆盖)
            if(dance(dep+1)) return 1;
            for(int j = L[i]; j != i; j = L[j]) resume(j);//resume(Col[j])(精确覆盖)
            resume(i);//新增(重复覆盖)
        }
        //resume(c);(精确覆盖)
        return 0;
    }

} dlx;
double Dis(int i, int j)
{
    double x = abs(city[j].first - rada[i].first);
    double y = abs(city[j].second - rada[i].second);
    return sqrt(x * x + y * y);
}
bool check(double md)
{
    dlx.init(n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        if(dis[i][j] <= md)
            dlx.link(i, j);
    return dlx.dance(0);
}
int main()
{
    jiasu;
    int T;
    cin>>T;
    while(T --)
    {
        cin>>n>>m>>k; 
        for(int i=1;i<=n;i++)
            cin>>city[i].first>>city[i].second;
        for(int i=1;i<=m;i++)
        {
            cin>>rada[i].first>>rada[i].second;
            for(int j=1;j<=n;j++)
                dis[i][j] = Dis(i, j);
        }
        double l = 0, r = 2000;
        while(r - l >= esp)
        {
            double md = (l + r) / 2;
            if(check(md))
            {
                r = md;
            }
            else 
            {
                l = md;
            }
        }
        cout<<fixed<<setprecision(6)<<l<<endl;
    }
    return 0;
}
