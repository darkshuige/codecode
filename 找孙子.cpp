#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
vector<int>g[maxn];
int sum[maxn]={0};
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			int v=g[i][j];
			sum[i]+=g[v].size();
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		 cout<<" ";
		cout<<sum[i];
	}
	cout<<endl;
	return 0;
}
