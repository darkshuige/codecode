#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200050;
int h[maxn],to[maxn],ne[maxn],tot=0;
void add(int a,int b)
{
	to[++tot]=b;ne[tot]=h[a];h[a]=tot;
}
int dfs(int u,int fa)
{
	int sg=0;
	for(int i=h[u];i;i=ne[i])
	{
		int v=to[i];
		if(v!=fa)
		 sg^=(dfs(v,u)+1);
	}
	return sg;
}
void init()
{
	tot=0;
	memset(h,0,sizeof h);
	memset(to,0,sizeof to);
	memset(ne,0,sizeof ne);
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		init();
		int n;
		cin>>n;
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			add(x,y),add(y,x);
		}
		int ans=dfs(1,-1);
		if(ans)
		 cout<<"Alice"<<endl;
		else
		 cout<<"Bob"<<endl;
	}
	return 0;
}
