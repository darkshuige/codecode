#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
vector<pair<int,int> >g[maxn];
int ans=INT_MIN;
int n;
int dfs(int u,int fa)
{
	int d1=0,d2=0;//d1,d2分别记录以u为根节点最长路径以及次长路径
				  //那么d1+d2就是以u为跟节点的最长路径
	for(auto kk:g[u])
	{
		int v=kk.first,w=kk.second;
		if(v==fa) continue;
		int d=dfs(v,u)+w; //dfs函数返回的是以v为根节点的最长路径所以要加上边权就是以u的长度
		if(d>d1)
		{
			d2=d1;
			d1=d;
		}
		else if(d>d2)
		 d2=d;
	}
	ans=max(ans,d1+d2);//遍历完所有的点d1就是最长d2就是次长
	return d1;
}
signed main()
{
	jiasu;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
} 
