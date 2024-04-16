#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
const double PI=3.141592;
//Hn=C(2n,n)-C(2n,n-1)    C(2n,n)/n+1    (4n-2)/(n+1)*h(n-1)
int a[20];
signed main()
{
	int n; cin>>n;
	a[0]=1;
	for(int i=1;i<=n;i++)
	 a[i]=(4*i-2)*a[i-1]/(i+1);
	cout<<a[n]<<endl;
	return 0;
} 	