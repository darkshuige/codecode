#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 2e9
using namespace std;
const int maxn=510;
const int maxm=125010;
int h[maxn],to[maxm<<1],ne[maxm<<1],idx=1,n,m;
double f[maxn][maxn];
double eps=1e-6;
double a[maxn][maxn],g[maxm],ans;
int d[maxn],s[maxm],t[maxm];//点的度，边的起点，终点
void add(int a,int b)
{
	to[idx]=b; ne[idx]=h[a]; h[a]=idx++;
}
void gauss()
{
	for(int i=1;i<n;i++)
	{
		for(int k=i;k<n;k++)
		 if(fabs(a[k][i])>eps)
		 {
			swap(a[k],a[i]); 
			break;
		}
		 for(int k=1;k<n;k++)
		 if(k!=i) for(int j=n;j>=i;j--)
		  a[k][j]-=a[k][i]/a[i][i]*a[i][j];	
	}
	for(int i=1;i<n;i++)
	 a[i][n]/=a[i][i];	
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	cin>>s[i]>>t[i];
    	add(s[i],t[i]); add(t[i],s[i]);
    	d[s[i]]++; d[t[i]]++;
	}
	for(int u=1;u<n;u++) //构建增广矩阵
 	{	
		for(int i=h[u];i;i=ne[i])
		{
			int v=to[i];
			if(v!=n)  //从v走到u的概率
			 a[u][v]=-1.0/d[v];
		}
		a[u][u]=1;
	}
	a[1][n]=1;
	gauss();
	for(int i=1;i<=m;i++)
	 g[i]=a[s[i]][n]/d[s[i]]+a[t[i]][n]/d[t[i]];
	sort(g+1,g+m+1);
	for(int i=1;i<=m;i++)
	 ans+=g[i]*(m-i+1);
	cout<<fixed<<setprecision(3)<<ans<<endl;
    return 0;
} 	