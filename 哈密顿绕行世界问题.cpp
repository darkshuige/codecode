#include<bits/stdc++.h>
#define jiasu ios sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=30;
int cnt,st;
vector<int>a[maxn];
bool vis[maxn];
vector<int>ans;
void dfs(int u,int sum)
{
	if(sum==20)
	{
		for(auto j:a[u])
		{
			if(j==st)
			{
				cout<<cnt<<": ";
				cnt++;
				for(auto j:ans)
				{
					cout<<" "<<j;
				}
				cout<<" "<<st<<endl;
				return ;	
			}
		}
	}
	for(auto v:a[u])
	{
		if(vis[v]==1) continue;
		vis[v]=1;
		ans.push_back(v);
		dfs(v,sum+1);
		vis[v]=0;
		ans.pop_back();
	}
}
signed main()
{
	for(int i=1;i<=20;i++)
	{
		int op;
		for(int j=0;j<3;j++)
		{
			cin>>op;
			a[i].push_back(op);	
		}
		sort(a[i].begin(),a[i].end());
	}
	int m;
	while(cin>>m)
	{
		if(m==0) break;
		ans.clear();
		memset(vis,0,sizeof vis);
		vis[m]=1;
		cnt=1;
		st=m;
		ans.push_back(m);
		dfs(m,1);
	}
	return 0;
}
