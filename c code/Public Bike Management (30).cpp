#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=205;
int a[maxn];
vector<pair<int,int> >g[maxn];
vector<pair<int,int> >pre[maxn];
deque<int>ans,aannss;
int d[maxn],vis[maxn];
int c,n,s,m;
void djst(int ss)
{
	memset(d,inf,sizeof d);
	memset(vis,0,sizeof vis);
	d[ss]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,ss});
	while(!q.empty())
	{
		auto op=q.top(); q.pop();
		int u=op.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto k:g[u])
		{
			int v=k.first,w=k.second;
			if(d[u]+w<=d[v])
			{
				d[v]=d[u]+w;
				q.push({d[v],v});
				pre[v].push_back({u,w});
			}
		}
	}
}
int mi=inf;
void dfs(int now,int cha,int ll)
{
	ans.push_back(now);
	if(now==0)
	{
		if(mi>abs(cha) && ll==d[s])
		{
			aannss=ans;
			mi=abs(cha);	
		}
		return ;
	}
	cha+=(c/2-a[now]);
	for(auto k:pre[now])
	{
		dfs(k.first,cha,ll+k.second);
		ans.pop_back();
	}
}
signed main()
{
	while(cin>>c>>n>>s>>m)
	{
		for(int i=0;i<=n;i++)
		{
			g[i].clear(); pre[i].clear();
		}
		a[0]=c/2;
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		while(m--)
		{
			int a,b,c; cin>>a>>b>>c;
			g[a].push_back({b,c});
			g[b].push_back({a,c});
		}
		djst(0);
		ans.clear();
		mi=inf;
		dfs(s,0,0);
		string lans;
		int num1=0,num2=0;
		while(!aannss.empty())
		{
			if(aannss.size()!=1)
			 lans+=to_string(aannss.back())+"->";
			else
			 lans+=to_string(aannss.back())+" ";
			if(a[aannss.back()]>=c/2)
			{
				num2+=(a[aannss.back()]-c/2);
			}
			else
			{
				if(num2>=(c/2-a[aannss.back()]))
				{
					num2-=(c/2-a[aannss.back()]);
				}
				else
				{
					num1+=(c/2-a[aannss.back()])-num2;
					num2=0;
				}
			}
			aannss.pop_back();
		}
		cout<<num1<<" "<<lans<<""<<num2<<endl;
	}
	return 0;
}