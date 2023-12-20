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
const int maxn=2000005;
struct node
{
	int u,v,w;
}a[maxn];
bool operator < (node a,node b)
{
	return a.w<b.w;
}
int d[maxn];
int f[maxn];
int n,m,ans;
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int cnt;
int ku()
{
	ans=0;
	cnt=0;
	for(int i=0;i<m;i++)
	{
		int ex=find(a[i].u);int ey=find(a[i].v);
		if(ex!=ey)
		{
			f[ex]=ey;
			ans+=a[i].w;
			cnt++;
		}
	}
	return cnt==n-1;
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
		init();
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>d[i];
		m=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[m].u=i;a[m].v=j;
				cin>>a[m].w;
				a[m].w+=d[i]+d[j];
				m++;
			}
		}
		sort(a,a+m);
		ku();
		cout<<ans<<endl;	
	}
		
    return 0;
}
