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
    int h()            //������A* �㷨�е� h��ֵ��������ʾ�ӵ�ǰ״̬������״̬���ٻ���Ҫ�ݹ���ٲ㣻
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
	{ //ѡȡ��d�� ��ǰ���, limit ���Ʋ��ܳ��������Χ
        /*�ظ�����
        1���������Ϊ�գ��õ����������
        2���Ӿ�����ѡ��һ�У���ѡȡ����Ԫ�ص���Ϊ�Ż���ʽ
        3��ɾ�����м��串�ǵ���
        4���Ը��е�ÿһ��Ԫ�أ�ɾ��һ�м��串�ǵ��У�
        5��������һ������������ɹ��򷵻�
        6���ָ��ֳ�������4
        7���ָ���ѡ����
        */
        if(dep + h() > k) return 0;
        if(R[0] == 0)
		{//ȫ��������
        //ȫ������֮��Ĳ���
			return dep<=k;
        }
        int c = R[0];//��ͷ���ָ��ĵ�һ����
        for(int i = R[0]; i != 0; i = R[i])//ö����ͷָ��
            if(S[i]<S[c])//�ҵ�����Ԫ�ظ������ٵ�
                c = i;
        //remove(c);//������ɾȥ(��ȷ����)
        for(int i = D[c]; i != c; i = D[i]){//ö�ٸ��е�Ԫ��
            remove(i);//����(�ظ�����)
            for(int j = R[i]; j != i; j = R[j]) remove(j);//remove(Col[j])(��ȷ����)
            if(dance(dep+1)) return 1;
            for(int j = L[i]; j != i; j = L[j]) resume(j);//resume(Col[j])(��ȷ����)
            resume(i);//����(�ظ�����)
        }
        //resume(c);(��ȷ����)
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
