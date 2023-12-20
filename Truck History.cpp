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
//#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2005;//用ff函数的时候赋值了两个string a和b一直超时 
struct node
{
	int u,v,w;
}a[maxn*maxn];
bool operator < (node a,node b)
{
	return a.w<b.w;
}
int f[maxn];
int n,m,ans;
char s[maxn][8];
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
void ku()
{
	ans=0;
	for(int i=0;i<m;i++)
	{
		int ex=find(a[i].u);int ey=find(a[i].v);
		if(ex!=ey)
		{
			f[ex]=ey;
			ans+=a[i].w;
		}
	}
}
void init()
{
	for(int i=0;i<=n;i++) f[i]=i;
}
int ff(int i,int j)
{
		int sum=0;
		string a=s[i],b=s[j];
		for(int i=0;i<7;i++)
		 if(a[i]!=b[i])
		  sum++;
		return sum;
}
signed main()
{
	//jiasu;
	while(scanf("%d", &n), n)
	{
		if(n==0) break;
		init();
		m=0;
		for(int i=1;i<=n;i++)
		 scanf("%s", s[i]);
		for(int i = 1; i <= n; i++)
		{
	      for(int j = i + 1; j <= n; j++)
		  {
	        a[m].u = i,a[m].v= j,a[m].w=ff(i,j);
	        m++;
	      }
	    }
		sort(a,a+m);
		ku();
		printf("The highest possible quality is 1/%d.\n", ans);
	}
    return 0;
}
