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
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
int n,k,ans;
bool vis[maxn];
int d[maxn];
void bfs(int now,int s)
{
	memset(vis,0,sizeof vis);
	memset(d,inf,sizeof d);
	d[now]=0;
	vis[now]=1;
	queue<int>q;
	q.push(now);
	while(!q.empty() && d[k]==inf)
	{
		int u=q.front();
		q.pop();
		if(u-1>=0 && vis[u-1]==0)
		{
			q.push(u-1);
			d[u-1]=d[u]+1;
			vis[u-1]=1;
		}
		if(vis[u+1]==0 && u+1<=100000)
		{
			q.push(u+1);
			d[u+1]=d[u]+1;
			vis[u+1]=1;
		}
		if(vis[u*2]==0 && u*2<=100000)
		{
			q.push(u*2);
			d[u*2]=d[u]+1;
			vis[u*2]=1;
		}
	}
}
signed main()
{
	jiasu;
	cin>>n>>k;
	ans=INT_MAX;
	bfs(n,0);
	cout<<d[k]<<endl;
	return 0;
 } 
