#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1000005;
int a[maxn],b[maxn];
signed main()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int i=1;i<=m;i++)
	 cin>>b[i];
	sort(a+1,a+1+n); sort(b+1,b+1+m);
	if(a[(1+n)/2]*n>b[(1+m)/2]*m)
	 cout<<"Yes"<<endl;
	else if(a[(1+n)/2]*n<b[(1+m)/2]*m)
	 cout<<"No"<<endl;
	else
	 cout<<"NY"<<endl;
	return 0;
}