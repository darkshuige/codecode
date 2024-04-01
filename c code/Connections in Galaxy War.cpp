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
using namespace std;
const int maxn=50005;
struct tunnel
{
	int a,b;
}tnl[maxn];
struct fw
{
	bool type;
	int q;
	tunnel d;
}qry[maxn];
int f[maxn],pl[maxn],ans[maxn];
map<tunnel,int>mp;
bool operator < (tunnel x,tunnel y)
{
	if(x.a!=y.a) return x.a<y.a;
	return x.b<y.b;
}
bool operator == (tunnel x,tunnel y)
{
	return x.a==y.a && x.b==y.b;
}
void init()
{
	for(int i=0;i<maxn;i++)
	 f[i]=i;
	mp.clear();
}
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void join(int x,int y)
{
	int ex=find(x);int ey=find(y);
	if(ex!=ey)
	{
		if(pl[ex]<pl[ey]) f[ex]=ey;
		else if(pl[ex]>pl[ey]) f[ey]=ex;
		else
		{
			if(ex<ey) f[ey]=ex;
			else f[ex]=ey;
		}
	}
}
signed main()
{
	int ca=0;
	int n,m;
	while(cin>>n)
	{
		init();
		for(int i=0;i<n;i++)
		 cin>>pl[i];
		cin>>m;
		for(int i=0;i<m;i++)
		 cin>>tnl[i].a>>tnl[i].b;
		int Q;
		cin>>Q;
		for(int i=0;i<Q;i++)
		{
			string s;
			cin>>s;
			if(s=="destroy")
			{
				tunnel t_;
				cin>>t_.a>>t_.b;
				qry[i].d=t_;
				qry[i].type=0;
				mp[t_]=1;
				mp[{t_.b,t_.a}]=1;
			}
			else
			{
				cin>>qry[i].q;
				qry[i].type=1;
			}
		}
		for(int i=0;i<m;i++)
		{
			tunnel t;
			t.a=tnl[i].a;t.b=tnl[i].b;
			if(mp[t]==0 && mp[{t.b,t.a}]==0)
			 join(tnl[i].a,tnl[i].b);
		}
		int cnt=0;
		for(int i=Q-1;i>=0;i--)
		{
			if(qry[i].type==1)
			{
				int rx=find(qry[i].q);
				if(rx!=qry[i].q && pl[rx]>pl[qry[i].q])
				 ans[cnt++]=rx;
				else
				 ans[cnt++]=-1;
			}
			else
			{
				join(qry[i].d.a,qry[i].d.b);
			}
		}
		if(ca) cout<<endl;
		ca++;
		for(int i=cnt-1;i>=0;i--)
		 cout<<ans[i]<<endl;
	}
    return 0;
}
