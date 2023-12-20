#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int a[maxn],b[maxn],n;
		cin>>n;
		for(int i=1;i<=n;i++)
		 cin>>a[i]>>b[i];
		sort(a+1,a+1+n),sort(b+1,b+1+n);
		if(n%2==0)
		 cout<<(a[n/2+1]-a[n/2]+1)*(b[n/2+1]-b[n/2]+1)<<endl;
		else
		 cout<<1<<endl;
	}
	return 0;
}
