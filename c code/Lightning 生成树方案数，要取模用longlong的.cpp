#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
//我们可以高斯消元得到上三角矩阵。
//然后把主对角线上的数都乘起来取绝对值就是行列式的绝对值了。
//无向图G的生成树个数就是基尔霍夫矩阵的任一n-1阶主子式的行列式的绝对值。
const int maxn=1010;
const int mod=10007;
double eps=1e-8;//切记两个double类型比较是否相等要用eps
int a[maxn][maxn],A[maxn][maxn];
set<int>st; 
struct nodes
{
	double x,y;
}node[600];
struct edges
{
	int u,v;
	double w;
}edge[600*600];
int f[600];
int n;
double dis(int i,int j)
{
	return (node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y);
}
void init()
{
	for(int i=0;i<600;i++) f[i]=i;
	memset(a,0,sizeof a);memset(A,0,sizeof A); 
}
int find(int x)
{
	if(f[x]==x) return f[x];
	else return f[x]=find(f[x]);
}
void join(int x,int y)
{
	int ex=find(x);int ey=find(y);
	if(ex!=ey) f[ex]=ey;
}
int check(int a,int b)
{
	for(int i=1;i<=n;i++)
	{
		if(i==a || i==b) continue;
		double x1=node[a].x,y1=node[a].y,x2=node[b].x,y2=node[b].y;
		double k=(y2-y1)/(x2-x1);
		if(node[i].y-y1==k*(node[i].x-x1) && sqrt(dis(i,a))+sqrt(dis(i,b))-sqrt(dis(a,b))<=eps)
		 return 0;
	}
	return 1;
}
int gauss(int n)
{
	n--;
	memcpy(A,a,sizeof a);
    int res = 1;
    for(int i = 1; i <= n; ++i)
	{
        for(int j = i + 1; j <= n; ++j)
		{
            while(A[j][i])
			{
                int t = A[i][i] / A[j][i];
                for(int k = i; k <= n; ++k)
                 A[i][k] = (A[i][k] - A[j][k] * t) % mod;
                for(int k = i; k <= n; ++k)
                 swap(A[i][k],A[j][k]);
                res = -res; //行列式换行，值取反
            }
        }
        if(!A[i][i]) return 0;
        res = res * A[i][i] % mod;
    }
    return (res + mod) % mod;
}
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		init();
		double r; cin>>n>>r;int m=0;
		for(int i=1;i<=n;i++)
		{
			cin>>node[i].x>>node[i].y;
			for(int j=1;j<i;j++)
			{
				edge[m].u=i;edge[m].v=j;edge[m++].w=dis(i,j);
			}
		}
		for(int i=0;i<m;i++)
		{
			int x=edge[i].u,y=edge[i].v;
			if(edge[i].w<=r*r && check(x,y))
			{
				join(x,y);
				a[x][x]++;a[y][y]++;a[x][y]=a[y][x]=-1;
			}
		}
		st.clear();
		for(int i=1;i<=n;i++) st.insert(find(i));
		if(st.size()>1) cout<<-1<<endl;
		else cout<<gauss(n)<<endl;
	}
	return 0;
}
