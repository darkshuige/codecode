#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=400000;
int f[maxn],d[maxn];//d表示到父节点的距离 
int ans;
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i,d[i]=0;
	ans=0;
}
int find(int x)
{
	if(x==f[x])
	 return x;
	int root=find(f[x]);
	d[x]+=d[f[x]];
	return f[x]=root;
	
}
void join(int x,int y,int _d)
{
	int ex=find(x);
	int ey=find(y);
	if(ex==ey)
	{
		if(d[x]-d[y]!=_d) 
		 ans++;
	}
	else
	{
		f[ex]=ey;
		d[ex]=_d+d[y]-d[x];//矢量？ 
	}
}
signed main()
{
	int n,m;
	while(cin>>n>>m)
	{
		init();
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			a--;
			join(a,b,c);
		}
		cout<<ans<<endl;
	}
	return 0;
}
