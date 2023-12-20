#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int f[maxn][3],n,vis[maxn];
vector<int>g[maxn];
void dp(int u)
{
	f[u][0]=1;//表示自己要拿 
	f[u][1]=0;//表示被子节点覆盖 
	f[u][2]=0;//表示被父节点覆盖
	vis[u]=1;
	int flag=0;
	int inc=INF;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];//子节点
		if(vis[v]==0)
		{
			dp(v);//递归
			f[u][0]+=min(f[v][0],min(f[v][1],f[v][2]));//u要拿，无所谓v点拿不拿，反正拿最小的
			f[u][2]+=min(f[v][0],f[v][1]);//因为u节点没拿，所以v节点不可能被父节点覆盖	
			if(f[v][0]<f[v][1])//开始处理f[u][1]即被子节点覆盖的情况 
			{
				flag=1;//如果出现要拿子节点的情况 
				f[u][1]+=f[v][0];//万事大吉直接拿 
			}
			else
			{
				inc=min(inc,(f[v][0]-f[v][1]));//inc要最小的 
				f[u][1]+=f[v][1];//仍然是拿小的但是要记录inc值 
			}		 
		}
	}
	if(flag==0)//f[u][1]没有从f[v][0]推过来，强制转化为从f[v][0]推过来
	 f[u][1]+=inc;
}
signed main()
{
	jiasu;
	while(cin>>n)
	{
		memset(vis,0,sizeof vis);
		memset(f,0,sizeof f);
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dp(1);
		cout<<min(f[1][0],f[1][1])<<endl;	
	}
	return 0;
} 
