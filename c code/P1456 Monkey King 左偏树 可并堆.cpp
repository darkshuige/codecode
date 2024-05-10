#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=100010;
int v[maxn],lc[maxn],rc[maxn],dis[maxn];//左偏树
int f[maxn];
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int merge(int x,int y)//递归合并
{
	if(!x || !y) return x+y;
	if(v[x]<v[y]) swap(x,y);
	rc[x]=merge(rc[x],y);
	f[rc[x]]=x;
	if(dis[lc[x]]<dis[rc[x]]) swap(lc[x],rc[x]);
	dis[x]=dis[rc[x]]+1;
	return x;
}
int weak(int x)
{
	v[x]>>=1;
	int rt=merge(lc[x],rc[x]);
	lc[x]=rc[x]=dis[x]=0;
	return f[rt]=f[x]=merge(rt,x);
}
signed main()
{
	jiasu;
	int n,m;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++) f[i]=i,dis[i]=0,lc[i]=0,rc[i]=0;
		for(int i=1;i<=n;i++) cin>>v[i];
		dis[0]=-1;
		cin>>m;
		while(m--)
		{
			int x,y; cin>>x>>y;
			x=find(x),y=find(y);
			if(x==y)
			{
				cout<<-1<<endl;
				continue;
			}
			int l=weak(x),r=weak(y);//削弱后重新选根
			f[l]=f[y]=merge(l,r);
			cout<<v[f[l]]<<endl;
		}	
	}
	return 0;
}

