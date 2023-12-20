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
//#define int long long
#define endl "\n"
#define inf 0x3f
using namespace std;
const int maxn=60000;
int f[maxn*2];
int n,k;
void init()
{
	for(int i=1;i<=n*2;i++)
	{
		f[i]=i;
	} 
}
int find(int x)
{
	if(x==f[x])
	 return x;
	else
	 return f[x]=find(f[x]);
}
void jion(int x,int y)
{
	int ex=find(x);int ey=find(y);
	if(ex!=ey)
	 f[ey]=ex;
}
signed main()
{
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		scanf("%d %d",&n,&k);
		init();
		int ans=0;
		for(int i=0;i<k;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			if(find(a)==find(b) || find(a+n)==find(b+n))
			{
				ans++;
				continue;
			}
			else
			{
				jion(find(a),find(b+n));
				jion(find(b),find(a+n));
			}
		}
		printf("Scenario #%d:\n",cnt);
		if(ans)
		 printf("Suspicious bugs found!\n\n");
		else
		 printf("No suspicious bugs found!\n\n");
	}
	
	return 0;
}
