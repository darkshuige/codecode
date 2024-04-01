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
#define inf 0x3f
using namespace std;
const int maxn=60000;
int f[maxn];
int n,m;
void init()
{
	for(int i=0;i<=n;i++) f[i]=i;
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
	while(cin>>n>>m)
	{
		if(n==0 && m==0) return 0;
		init();
		for(int i=0;i<m;i++)
		{
			int k;
			cin>>k;
			if(k==0) continue;
			int st;
			cin>>st;
			for(int j=0;j<k-1;j++)
			{
				int op;
				cin>>op;
				int ex=find(st);int ey=find(op);
				if(ex!=ey)
				 f[ex]=ey;
				st=op;
			}
		}
		int ss=find(0);
		int ans=0;
		for(int i=0;i<=n;i++)
		 if(find(i)==ss) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
