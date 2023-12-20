#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxNumumumumumumumumumumumumum=100005;
bool vis[maxNumumumumumumumumumumumumum];
int ans,n;
struct node
{
	int cost;
	int id;
	double rq;
}a[maxNumumumumumumumumumumumumum];
struct cmp
{
	bool operator() (node a,node b)
	{
		return a.rq>b.rq;
	}
};
void prim(vector<int>d[],priority_queue<node,vector<node>,cmp>q)
{
	while(!q.empty())
	{
		auto op=q.top();
		q.pop();
		int v=op.id;
		while(vis[v]==1)
		{
			if(q.empty())
			 return;
			op=q.top();
			v=op.id;
			q.pop();
		}
		vis[v]=1;
		ans+=op.cost;
		for(int k=0;k<d[v].size();k++)
		{
			vis[d[v][k]]=1;
		}
	}
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		memset(vis,0,sizeof vis);
		vector<int>d[n+1];
		memset(a,0,sizeof(node)*maxNumumumumumumumumumumumumum);
		priority_queue<node,vector<node>,cmp>q;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].cost;
			a[j].id=j;
		}
		for(int j=0;j<n-1;j++)
		{
			int l,r;
			cin>>l>>r;
			d[l].push_back(r);
			d[r].push_back(l);
		}
		for(int j=1;j<=n;j++)
		{
			a[j].rq=a[j].cost*1.0/d[j].size();
			q.push(a[j]);
		}
		ans=0;
		prim(d,q);
		cout<<ans<<endl;
	}
	return 0;
} 
