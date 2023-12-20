#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
vector<int>graph[maxn];
int ind[maxn]={0},n;
signed main()
{
	int m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		ind[y]++;
	}
	int number=0;
	queue<int>q,ans;
	for(int i=1;i<=n;i++)
	{
		if(ind[i]==0)
		{
			q.push(i);
			ans.push(i);
			number++;
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int j=0;j<graph[u].size();j++)
		{
			int v=graph[u][j];
			ind[v]--;
			if(ind[v]==0)
			{
				q.push(v);
				ans.push(v);
				number++;
			}
		}
	}
	if(number==n)
	{
		cout<<1<<endl;
		int cnt=0;
		while(!ans.empty())
		{
			if(cnt!=0)
			 cout<<" ";
			cout<<ans.front();
			cnt++;
			ans.pop();
		} 
	}
	else
	{
		cout<<2<<endl;
		for(int i=1;i<=n;i++)
		{
			if(i!=1)
			 cout<<" ";
			cout<<i;
		}
		cout<<endl;
		for(int i=n;i>=1;i--)
		{
			if(i!=n)
			 cout<<" ";
			cout<<i;
		}
		cout<<endl;
	}
	return 0;
} 
