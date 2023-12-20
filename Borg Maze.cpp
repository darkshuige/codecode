#include <iostream>
#include <cstdio>
#include <algorithm>
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
#include<string>
#include<stack>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=5000;
int n,m,pp;
map<pair<int,int>,int>mp;
struct node
{
	int u,v,w;
}a[maxn];
bool operator < (node a,node b)
{
	return a.w<b.w;
}
int f[maxn];
int ans;
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int cnt;
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
	mp.clear();
}
char s[1000][1000];
int d[100][100],vis[100][100];
int ex[]={-1,+0,+1,+0};
int ey[]={+0,+1,+0,-1};
void bfs(int x,int y)
{
	memset(d,inf,sizeof d);
	memset(vis,0,sizeof vis);
	d[x][y]=0;vis[x][y]=1;
	queue<pair<int,int> >q;
	q.push({x,y});
	while(!q.empty())
	{
		pair<int,int>p=q.front();q.pop();
		int x=p.first,y=p.second;
		for(int i=0;i<4;i++)
		{
			int xx=x+ex[i],yy=y+ey[i];
			if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
			if(s[xx][yy]=='#' || vis[xx][yy]) continue;
			d[xx][yy]=d[x][y]+1;
			vis[xx][yy]=1;
			q.push({xx,yy});
		}
	}
}
void ku()
{
	ans=0;
	for(int i=0;i<pp;i++)
	{
		int ex=find(a[i].u);int ey=find(a[i].v);
		if(ex!=ey)
		{
			f[ex]=ey;
			ans+=a[i].w;
		}
	}
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int kk=0;kk<t;kk++)
	{
		cin>>m>>n;
		char fw[1000];
		gets(fw);
		init();
		for(int i=0;i<n;i++)
		 gets(s[i]);
		int p=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(s[i][j]=='A' || s[i][j]=='S')
				 mp[make_pair(i,j)]=p++;
			}
		}
		map<pair<int,int>,int>::iterator it,it2;
 		pp=0;
		for(it=mp.begin();it!=mp.end();it++)
		{
			int x=it->first.first,y=it->first.second;int u=it->second;
			bfs(x,y);
			for(it2=mp.begin();it2!=mp.end();it2++)
			{
				int v=it2->second;
				if(v==u) continue;
				a[pp].u=u,a[pp].v=v,a[pp++].w=d[it2->first.first][it2->first.second];
			}
		}
		sort(a,a+pp);
		ku();
		cout<<ans<<endl;
	}
    return 0;
}
