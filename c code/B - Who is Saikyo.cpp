#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=60;
vector<int>g[maxn];//记录比他大的数 
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 g[i].clear();
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[b].push_back(a);
	}
	int cnt=0,pos=-1;
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()==0)
		{
			cnt++;
			pos=i;
		}
	}
	if(cnt==1)
	 cout<<pos<<endl;
	else
	 cout<<-1<<endl;
	return 0;
}
