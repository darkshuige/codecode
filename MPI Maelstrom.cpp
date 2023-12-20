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
#include<iomanip>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=110;
int n;
struct edge
{
	int u,v,w;
	friend bool operator < (const edge a,const edge b)
	{
		return a.w>b.w;
	}
};
priority_queue<edge>q;
int f[maxn];
void init()
{
	for(int i=0;i<=n;i++)
	 f[i]=i;
}
int find(int x)
{
	if(x==f[x])
	 return x;
	else
	 return x=find(f[x]);
}
signed main()
{
	jiasu;
	cin>>n;
	init();
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			string s;
			cin>>s;
			if(s[0]=='x') continue;
			int sum=0;
			for(int k=0;k<s.size();k++)
			 sum=sum*10+(s[k]-'0');
			edge a;a.u=i;a.v=j;a.w=sum;
			q.push(a);
		}
	}
	int ans=0;
	int cnt=0;
	while(!q.empty() && cnt<n-1)
	{
		edge op=q.top();q.pop();
		int v=op.v,u=op.u,w=op.w;
		int ex=find(v);int ey=find(u);
		if(v!=u)
		{
			f[v]=u;
			ans+=w;
			cnt++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
