#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=300005;
int a[maxn],f[maxn],b[maxn];
int m,n,p;
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b & 1) res=res*a;
		a*=a;
		b>>=1;
	}
	return res;
}
int sg(int x)
{
	if(f[x]!=-1) return f[x];
	set<int>s;
	for(int i=0;i<m;i++)
	 if(x>=a[i]) s.insert(sg(x-a[i]));
	for(int i=0;;i++)
	 if(!s.count(i)) return f[x]=i;
}
signed main()
{
	jiasu;
	cout<<ksm(2,60);
	return 0;
}