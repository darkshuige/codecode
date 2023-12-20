#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
using namespace std;
const int maxn=100005;
struct edge
{
	int u,v,len,nex;	
}e[maxn*2];
int h[maxn],indx;
int ch[maxn*31][2],cnt;
int sum[maxn];
void add(int u,int v,int len)
{
	e[++indx]={u,v,len,h[u]};
	h[u]=indx;
}
void dfs(int u,int fa)//u~1的？ 
{
	for(int i=h[u];i;i=e[i].nex)//i一开始等于u的头指针位置，后面开始便利u的相邻点 
	{
		int v=e[i].v,w=e[i].len;
		if(v==fa)//有环？ 
		 continue;
		sum[v]=sum[u]^w;
		dfs(v,u);
	}
}
void insert(int x)
{
	int p=0;
	for(int i=30;i>=0;i--)
	{
		int j=x>>i&1;
		if(!ch[p][j])
		 ch[p][j]=++cnt;
		p=ch[p][j];
	}
}
int query(int x)
{
	int ans=0;
	int p=0;
	for(int i=30;i>=0;i--)
	{
		int j=x>>i&1;
		if(ch[p][!j])
		{
			p=ch[p][!j];
			ans+=1<<i;
		}
		else
		 p=ch[p][j];
	}
	return ans;
}
signed main()
{
	int n;
	cin>>n;
	indx=0;
	for(int i=1;i<n;i++)
	{
		int u,v,len;
		cin>>u>>v>>len;
		add(u,v,len),add(v,u,len);
	}
	dfs(1,0);
	cnt=0;
	for(int i=1;i<=n;i++)
	 insert(sum[i]);
	int res=0;
	for(int i=1;i<=n;i++)
	 res=max(res,query(sum[i]));
	cout<<res<<endl;
	return 0;
}
