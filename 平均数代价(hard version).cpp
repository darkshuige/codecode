#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int dist[maxn];
int n,p,x,q,y;
void bfs(int k)
{
	queue<int>qq;
	qq.push(k);
	for(int i=0;i<=n;i++)
	 dist[i]=INF;
	dist[k]=0;
	while(!qq.empty())
	{
		int u=qq.front();
		qq.pop();
		int a=((u+x)%n+n)%n,w1=p;
		int b=((u-y)%n+n)%n,w2=q;
		if(dist[u]+w1<dist[a])
		{
			dist[a]=dist[u]+w1;
			qq.push(a);
		}
		if(dist[u]+w2<dist[b])
		{
			dist[b]=dist[u]+w2;
			qq.push(b);
		}
	}
}
signed main()
{
	jiasu;
	cin>>n>>p>>x>>q>>y;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		sum+=op;
	}
	if(sum%n==0)
	{
		cout<<0<<endl;
		return 0;
	}
	int k=sum%n;
	bfs(k);
	if(dist[0]==INF)
	 cout<<-1<<endl;
	else
	 cout<<dist[0]<<endl;
	return 0;
}
