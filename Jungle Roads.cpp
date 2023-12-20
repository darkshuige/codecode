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
const int maxn=1000005;
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
int ku()
{
	int cnt=0;
	ans=0;
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
	while(cin>>n)
	{
		if(n==0) break;
		init(); 
		m=0;
		for(int i=0;i<n-1;i++)
		{
			char op;
			cin>>op;
			int u=(op-'A');
			int k;
			cin>>k;
			for(int j=0;j<k;j++)
			{
				a[m].u=u;
				char op;
				cin>>op;
				a[m].v=(op-'A');
				cin>>a[m++].w;
			}
		}
		sort(a,a+m);
		ku();
		cout<<ans<<endl;	
	}
    return 0;
}
