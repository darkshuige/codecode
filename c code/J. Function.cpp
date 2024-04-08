#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=500005;
int a[maxn];
signed main()
{
	jiasu;
	int n,p; cin>>n>>p;
	int s=0;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		s^=x;
	}
	if(s==0)
	{
		if(p & 1)
		 cout<<"GOOD"<<endl;
		else
		 cout<<"BAD"<<endl;
	}
	else 
	{
		if(p & 1)
		 cout<<"BAD"<<endl;
		else
		 cout<<"GOOD"<<endl;
	}
	return 0;
}