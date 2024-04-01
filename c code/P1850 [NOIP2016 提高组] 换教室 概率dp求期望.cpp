#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 2e9
using namespace std;
const int maxn=3000;
double dist[maxn][maxn];
double dp[maxn][maxn][2];//dp[i][j][1/0]表示到第i节课，申请了j次，是否申请的最小值
int c[maxn],d[maxn];
double p[maxn];
signed main()
{
	jiasu;
	int n,m,v,e;
	cin>>n>>m>>v>>e;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=v;i++)
	 for(int j=1;j<=v;j++)
	  dist[i][j]=dist[j][i]=inf;
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		dist[a][b]=dist[b][a]=min(dist[a][b],c*1.0);
	}
	for(int k=1;k<=v;k++)
	 for(int i=1;i<=v;i++)
	  for(int j=1;j<i;j++)
	   if(dist[i][j]>dist[i][k]+dist[k][j])
	    dist[i][j]=dist[j][i]=dist[i][k]+dist[k][j];
	for(int i=1;i<=n;i++)
	 for(int j=0;j<=m;j++)
	  dp[i][j][0]=dp[i][j][1]=inf;
	dp[1][0][0]=dp[1][1][1]=0;
	for(int i=2;i<=n;i++)//枚举第几节课
	{
		for(int j=0;j<=min(m,i);j++)//枚举用了几次机会
		{   //这次不换
			dp[i][j][0]=min(dp[i-1][j][0]+dist[c[i-1]][c[i]],dp[i-1][j][1]+p[i-1]*dist[d[i-1]][c[i]]+(1.0-p[i-1])*dist[c[i-1]][c[i]]);
			if(j>0)//这次换
				dp[i][j][1]=min(dp[i-1][j-1][0]+dist[c[i-1]][c[i]]*(1.0-p[i])+dist[c[i-1]][d[i]]*(p[i]),
				dp[i-1][j-1][1]
				+dist[c[i-1]][c[i]]*(1-p[i])*(1-p[i-1])
				+dist[c[i-1]][d[i]]*(p[i])*(1-p[i-1])
				+dist[d[i-1]][c[i]]*(1-p[i])*(p[i-1])
				+dist[d[i-1]][d[i]]*(p[i])*(p[i-1]));
		}
	}
	double ans=inf;
	for(int i=0;i<m;i++)
	 ans=min(ans,min(dp[n][i][0],dp[n][i][1]));
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
} 
