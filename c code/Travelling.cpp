#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;
int n,m,cnt;
struct node
{
	int x;int y;int z;
	friend bool operator < (const node a,const node b)
	{
		return a.z>b.z;
	}
};
int f[maxn];
void init()
{
	for(int i=1;i<=n;i++)
	 f[i]=i;
}
int find(int x)
{
	if(f[x]==x)
	 return x;
	else
	 return x=find(f[x]);
}
map<pair<int,int>,int>mp;
priority_queue<node>q;
signed main()
{
	jiasu;
	while(cin>>n>>m)
	{
		init();
		cnt=0;
		int sum=0;
		mp.clear();
		while(!q.empty()) q.pop();
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			pair<int,int>op{x,y};
			if(mp.count(op)!=0)
			 mp[op]=min(mp[op],z);
			else
			 mp[op]=z;
		}
		for(auto it:mp)
		{
			int x=it.first.first;
			int y=it.first.second;
			int z=it.second;
			q.push({x,y,z});
		}
		while(cnt<n-1)
		{
			node op=q.top();q.pop();
			int x=op.x,y=op.y;
			int ex=find(x);int ey=find(y);
			if(ex!=ey)
			{
				sum+=op.z;
				f[y]=x;
				cnt++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
