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
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2002;
int f[maxn],fix[maxn];
double x[maxn],y[maxn];
int n;
void init()
{
	for(int i=1;i<=n;i++) f[i]=i;
}
int find(int x)
{
	if(x==f[x])
	 return x;
	else
	 return f[x]=find(f[x]);
}
signed main()
{
	jiasu;
	double d;
	cin>>n>>d;
	init();
	memset(fix,0,sizeof fix);
	for(int i=1;i<=n;i++)
	 cin>>x[i]>>y[i];
	char op;
	while(cin>>op)
	{
		if(op=='O')
		{
			int k;
			cin>>k;
			if(fix[k]) continue;
			fix[k]=1;
			for(int i=1;i<=n;i++)
			{
				if(i==k || fix[i]==0) continue;
				double l=(x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k]);
				if(l<=d*d)
				{
					int ex=find(i);int ey=find(k);
					if(ex!=ey)
					{
						f[ey]=ex;
					}
				}
			}
		}
		else
		{
			int a,b;
			cin>>a>>b;
			int ex=find(a);int ey=find(b);
			if(ex==ey)
			 cout<<"SUCCESS"<<endl;
			else
			 cout<<"FAIL"<<endl;
		}
	}
	return 0;
}
