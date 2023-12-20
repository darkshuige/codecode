#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200005;
int a[maxn];
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		int sum=0;
		a[1]+=1;
		sort(a,a+n);
		for(int i=1;i<n-1;i++)
		 sum+=a[i];
		cout<<sum<<endl;
	}
	return 0;
} 
