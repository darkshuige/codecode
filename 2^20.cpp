#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
const int m=1<<20;
unordered_map<int,int>mp,vis;
void bfs(int n)
{
	mp[n]=0;vis[n]=1;
	queue<int>q;
	q.push(n);
	while(!q.empty())
	{
		int a=q.front();q.pop();
		if(a%m==0)
		{
			mp[0]=mp[a];
			vis[0]=1;
			return ;
		}
		int b=a+1;
		if(vis.count(b)==0)
		{
			mp[b]=mp[a]+1;
			vis[b]=1;
			q.push(b);
		}
		b=a*2;
		if(vis.count(b)==0)
		{
			mp[b]=mp[a]+1;
			vis[b]=1;
			q.push(b);
		}
	}
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		mp.clear();
		vis.clear();
		int n;
		cin>>n;
		bfs(n);
		if(vis[0])
		 cout<<mp[0]<<endl;
		else
		 cout<<-1<<endl;
	}
	return 0;
}
