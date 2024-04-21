#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
vector<int>g[maxn];
set<int>st;
vector<int>ans;
void dfs(int u,int fa)
{
	ans.push_back(u);
	for(auto v:g[u])
	{
		if(v!=fa)
		 dfs(v,u);
	}
}
signed main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b; cin>>b;
		a=i;
		g[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
	 sort(g[i].begin(),g[i].end());
	int du=LLONG_MIN;
	for(int i=1;i<=n;i++)
	{
		du=max(du,(int)g[i].size());
		st.insert(g[i].size());
	}
	cout<<du<<" ";
	if(st.size()==2) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	int root=g[0][0];
	dfs(root,0);
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}