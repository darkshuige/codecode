#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#include<iomanip>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=40;
struct edge
{
	int v;double w;
};
vector<edge>g[maxn];
double d[maxn];
int vis[maxn],cnt[maxn];
int n;
int spfa(int st)
{
	memset(cnt,0,sizeof cnt);
	memset(vis,0,sizeof vis);
	memset(d,0,sizeof d);
	vis[st]=0;d[st]=100;
	queue<int>q;
	q.push(st);
	while(!q.empty())
	{
		int op=q.front();q.pop();vis[op]=0;
		for(int i=0;i<g[op].size();i++)
		{
			edge a=g[op][i];
			double w=a.w;int v=a.v;
			if(d[op]*w>d[v])
			{
				d[v]=d[op]*w;
				cnt[v]=cnt[op]+1;
				if(cnt[v]>=n) return 1;
				if(vis[v]==0)
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return 0;
}
signed main()
{
	jiasu;
	int cnt=1;
	while(cin>>n)
	{
		if(n==0) break;
		map<string,int>mp;
		int pos=1;
		for(int i=0;i<maxn;i++) g[i].clear();
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			if(!mp.count(s))
			 mp[s]=pos++;
		}
		int m;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			string a,b;
			double w;
			cin>>a>>w>>b;
			edge op;op.v=mp[b];op.w=w;
			g[mp[a]].push_back(op);
		}
		cout<<"Case "<<cnt<<": ";
		cnt++;
		if(spfa(1))
		 cout<<"Yes"<<endl;
		else
		 cout<<"No"<<endl;
	}
	return 0;
}
