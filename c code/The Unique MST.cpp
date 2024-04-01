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
#define endl "\n"
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=400000;
struct node
{
	int u,v,w;
}a[maxn];
bool operator < (node a,node b)
{
	return a.w<b.w;
}
int f[maxn];
int n,m,ans;
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int flag,cnt;
void ku()
{
	ans=0;cnt=0;
	for(int i=0;i<m;i++)
	{
		int pos=i+1;
		while(pos<m && a[pos].w==a[i].w)
		{
			int ex1=find(a[i].u);int ey1=find(a[i].v);
			int ex2=find(a[pos].u);int ey2=find(a[pos].v);
			if((ex1==ex2 && ey1==ey2) || (ex1==ey2 && ex2==ey1)) flag=0;
			pos++;
		}
		int ex=find(a[i].u);int ey=find(a[i].v);
		if(ex!=ey)
		{
			f[ex]=ey;
			ans+=a[i].w;
			cnt++; 
		}
	}
}
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		init();
		for(int i=0;i<m;i++)
		 cin>>a[i].u>>a[i].v>>a[i].w;
		sort(a,a+m);
		flag=1;
		ku();
		if(flag && cnt==n-1)
		 cout<<ans<<endl;
		else
		 cout<<"Not Unique!"<<endl;	
	}
	
    return 0;
}
