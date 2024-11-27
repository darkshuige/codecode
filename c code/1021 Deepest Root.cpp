#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10005;
int f[maxn];
void init(int n)
{
	for(int i=0;i<=n;i++) f[i]=i;
}
int find(int x)
{
	if(f[x]==x) return f[x];
	else return f[x]=find(f[x]);
}
vector<int>g[maxn];
set<int>st;
map<int,vector<int> >mp;
int vis[maxn];
int dfs(int now,int fa)
{
	vis[now]=1;
	for(auto v:g[now])
	{
		if(vis[v]==1 && v!=fa)
		 return 0;
		if(v==fa) continue;
		dfs(v,now);
	}
	return 1;
}
int total;
void bfs(int now)
{
	queue<int>q;
	q.push(now);
	memset(vis,0,sizeof vis);
	vis[now]=1;
	while(!q.empty())
	{
		int ct=q.size();
		total++;
		for(int i=0;i<ct;i++)
		{
			int now=q.front();q.pop();
			vis[now]=1;
			for(auto k:g[now])
			{
				if(vis[k]) continue;
				q.push(k);
			}	
		}
	}
}
signed main()
{
	jiasu;
	int n; cin>>n;
	init(n);
	for(int i=0;i<n-1;i++)
	{
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		int xx=find(a),yy=find(b);
		if(xx!=yy) f[xx]=yy;
	}
	st.clear();
	for(int i=1;i<=n;i++) st.insert(find(i));
	memset(vis,0,sizeof vis);
	int pos=dfs(1,0);
	if(pos==0 || st.size()!=1)
	 cout<<"Error: "<<st.size()<<" components"<<endl;
	else
	{
		for(int i=1;i<=n;i++)
		{
			total=0;
			bfs(i);
			mp[total].push_back(i);
		}
		auto it=mp.begin();
		for(it;it!=mp.end();it++);
		it--;
		for(auto k:(*it).second)
		 cout<<k<<endl;
	}
	return 0;
} 