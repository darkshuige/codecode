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
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
using namespace std;
const int maxn=50500;
int va[maxn];
int a[maxn];
int f[maxn];
struct node
{
	int x,y,z;
}node[maxn];
void init()
{
	for(int i=0;i<maxn;i++)
	{
		va[i]=0;//0表示相同，1表示不同
		f[i]=i; 
	}
}
int find(int x)
{
	if(x==f[x])
	 return x;
	int t=find(f[x]);
	va[x]^=va[f[x]];
	return f[x]=t;
}
void join(int x,int y,int z)
{
	int ex=find(x);int ey=find(y);
	if(ex==ey) return ;
	else
	{
		f[ex]=ey;
		va[ex]=va[x]^va[y]^z;
	}
}
signed main() 
{
    jiasu;
    int n,q;
	cin>>n>>q;
    init();
    int p=1;
    for(int i=0;i<q;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	x--;
    	a[p]=x;node[i].x=x;p++;
    	a[p]=y;node[i].y=y;p++;
    	string s;
    	cin>>s;
    	if(s=="even") node[i].z=0;
    	else node[i].z=1;
	}
	p--;
	sort(a,a+p);
	int len=unique(a,a+p)-a;
	int ans=q;
	for(int i=0;i<q;i++)
	{
		int x=lower_bound(a,a+len,node[i].x)-a;
		int y=lower_bound(a,a+len,node[i].y)-a;
		int ex=find(x);int ey=find(y);
		if(ex!=ey)
		 join(x,y,node[i].z);
		else
		{
			if(va[x]^va[y]!=node[i].z)
			{
				ans=i;
				break;
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}
