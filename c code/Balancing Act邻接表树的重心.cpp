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
using namespace std;
const int maxn=40005;
int vis[maxn];
int h[maxn],to[maxn],ne[maxn],idx;
int ans,n,pos;
void init()
{
	memset(h,-1,sizeof h);
	memset(vis,0,sizeof vis);
	idx=0;
	ans=INT_MAX;
}
void add(int a,int b)
{
	to[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
int dfs(int u)
{
	vis[u]=1;
	int sum=1;//表示以u为根节点一共有多少个点 
	int size=0;//表示最大的子树有多少个点 
	for(int i=h[u];~i;i=ne[i])//遍历 
	{
		int j=to[i];
		if(vis[j])
		 continue;
		int s=dfs(j);//返回j子树的一共点数 
		sum+=s;
		size=max(size,s);
	}
	//	ans=min(ans,max(size,n-sum));//最大的数可能来自于最大的子树或者是上面，n-num表示上面，size是最大的子树
	int mx=max(size,n-sum);
	if(mx<ans)
	{
		ans=mx;
		pos=u;
	}
	return sum;//dfs返回的是这个树一共有多少个点，在返回之前判断一下这个点的ans 
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		init();
		cin>>n;
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}	
		dfs(1);
		cout<<pos<<" "<<ans<<endl;
	}
	return 0;
}
