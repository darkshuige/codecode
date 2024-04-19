#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
int h[maxn],to[maxn],ne[maxn],idx=0;
int w[maxn],r1,r2,vis[maxn];
int f[maxn][2],sum;
void add(int a,int b)
{
	to[idx]=b; ne[idx]=h[a]; h[a]=idx++;
}
void find(int u,int rt) //找两个根，就是找环中一条边的两个顶点
{
	vis[u]=1;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int v=to[i];
		if(v==rt)//找到了
		{
			r1=u,r2=v;
			return ;
		}
		if(vis[v]) continue;
		find(v,rt);
	}
}
int dfs(int u,int rt)//书上dp (没有上司的舞会)
{
	f[u][0]=0,f[u][1]=w[u];
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int v=to[i];
		if(v==rt) continue;//这条边当做不存在，直接回溯
		dfs(v,rt);//回来的时候加
		f[u][0]+=max(f[v][0],f[v][1]);
		f[u][1]+=f[v][0];
	}
	return f[u][0];
}
signed main()
{
	jiasu;
	int n; cin>>n;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n;i++)
	{
		int v; cin>>w[i]>>v;
		add(v,i);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{	
			r1=r2=0;
			find(i,i);
			if(r1)
			{
				int res1=dfs(r1,r1);
				int res2=dfs(r2,r2);
				sum+=max(res1,res2);
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}