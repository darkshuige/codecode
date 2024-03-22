#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
const int maxn=300;
vector<pair<int,int>>g[maxn];
bool vis[maxn];
int n,q,x,s,t,fu;
int d[maxn];
int w[maxn];
void bfs(int s)
{
	memset(vis,0,sizeof vis);
    fill(d+1,d+n+1,M);
    d[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
	{
        int u=q.front(); q.pop();
        if(vis[u])
		 continue;
        vis[u]=1;
        if(u==t) return ;
        for(int i=0;i<g[u].size();i++)
		{
            int v=g[u][i].first;
            if(w[v]>fu) continue;
            if(d[v]>d[u]+g[u][i].second)
			{
                d[v]=d[u]+g[u][i].second;
                q.push(v);
            }
        }
    }
}
signed main()
{
	jiasu;
	int cc;
	cin>>cc;
	int cnt=1;
	while(cc--)
	{
		cin>>n>>q;
		for(int i=1;i<=n;i++) cin>>w[i],g[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int x; cin>>x;
				if(i==j) continue;
				g[i].push_back({j,x});
			}
		}
		cout<<"Case #"<<cnt<<":"<<endl;
		cnt++;
		while(q--)
		{
			cin>>s>>t>>fu;
			if(s==t)
			{
				cout<<0<<endl;
				continue;
			}
			int temp=w[t]; w[t]=0;
			bfs(s);
			w[t]=temp;
			cout<<d[t]<<endl;
		}
	}
    
    return 0;
} 
