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
int f[maxn*3];
int n,k;
void init()
{
	for(int i=1;i<=n*3;i++)
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
	scanf("%d %d",&n,&k);
	init();
	int ans=0;
	for(int i=0;i<k;i++)
	{
		int op,a,b;
	scanf("%d %d %d",&op,&a,&b);
		if(a>n || b>n || (op==2 && a==b)) ans++;
		else if(op==1)
		{
			if(find(a+n)==find(b) || find(a)==find(b+n)) ans++;
			else
			{
				jion(find(a),find(b));
				jion(find(a+n),find(b+n));
				jion(find(a+2*n),find(b+2*n));
			}
		}
		else if(op==2)
		{
			if(find(a)==find(b) || find(b+n)==find(a)) ans++;
			else
			{
				jion(find(a+n),find(b));
				jion(find(b+2*n),find(a));
				jion(find(a+2*n),find(b+n));
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
