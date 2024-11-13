#include<bits/stdc++.h>
//#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=205;
int a[maxn];
int n,m,cnt,ed;
string s;
map<string,int>mp;
map<int,string>mp2;
vector<pair<int,int> >g[maxn];
int d[maxn];
bool vis[maxn];
vector<pair<int,int> >pre[maxn];
void djst(int st)
{
	memset(d,inf,sizeof d);
	memset(vis,0,sizeof vis);
	d[0]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >q;
	q.push({0,st});
	while(!q.empty())
	{
		auto k=q.top(); q.pop();
		int u=k.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto j:g[u])
		{
			int v=j.first,w=j.second;
			if(d[u]+w<=d[v])
			{
				d[v]=d[u]+w;
				pre[v].push_back({u,w});
				q.push({d[v],v});
			}
		}
	}
}
deque<int>ans,aannss;
int ma=-inf,num,mi=inf;
void dfs(int now,int ll,int total,int city)
{
	total+=a[now];
	ans.push_back(now);
	if(now==0)
	{
		if(ll==d[ed])
		{
			num++;
			if(total>ma)
			{
				ma=total;
				mi=city;
				aannss=ans;
			}
			else if(total==ma)
			{
				if(city<mi)
				{
					mi=city;
					ma=total;
					aannss=ans;
				}
			}
		}
		return ;
	}
	for(auto k:pre[now])
	{
		int v=k.first,w=k.second;
		dfs(v,ll+w,total,city+1);
		ans.pop_back();
	}
}
signed main()
{
	jiasu;
	while(cin>>n>>m>>s)
	{
		for(int i=0;i<=n;i++)
		{
			g[i].clear();
			pre[i].clear();
		}
		mp2.clear();
		mp.clear();
		a[0]=0;
		cnt=0;
		mp[s]=cnt;
		mp2[cnt++]=s;
		for(int i=0;i<n-1;i++)
		{
			string ss; cin>>ss;
			mp[ss]=cnt;
			mp2[cnt]=ss;
			if(ss=="ROM") ed=cnt;
			cin>>a[cnt++];
		}
		while(m--)
		{
			int c;
			string a,b; cin>>a>>b>>c;
			int aa=mp[a],bb=mp[b];
			g[aa].push_back({bb,c});
			g[bb].push_back({aa,c});
		}
		djst(0);
		num=0;
		ma=-inf,mi=inf;
		dfs(ed,0,0,0);
		cout<<num<<" "<<d[ed]<<" "<<ma<<" "<<ma/mi<<endl;
		while(!aannss.empty())
		{
			cout<<mp2[aannss.back()];
			aannss.pop_back();
			if(aannss.size()!=0)
			 cout<<"->";
			else
			 cout<<endl;
		}
	}
	return 0;
}