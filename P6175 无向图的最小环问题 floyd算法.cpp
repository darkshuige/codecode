#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
#define inf 1e9
using namespace std;
const int maxn =200;
int g[maxn][maxn],w[maxn][maxn];
signed main()//如果用0x3f3f3f3f3f3f3f3f的话，三条边加上去可能会爆，所以要小一点然后ans的初值要更小一点不然
//可能并没有连通但是也输出了 
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<maxn;i++)
	 for(int j=0;j<maxn;j++)
	  if(i!=j) g[i][j]=inf; else g[i][j]=0;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b]=g[b][a]=c;
	}
	memcpy(w,g,sizeof w);
	int ans=1e8;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
		 for(int j=i+1;j<k;j++)
		  ans=min(ans,g[i][j]+w[i][k]+w[k][j]);
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=n;j++)
		  g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	}
	if(ans!=1e8)
	 cout<<ans<<endl;
	else
	 cout<<"No solution."<<endl;
    return 0;
}
