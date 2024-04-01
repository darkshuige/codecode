#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;
int a[maxn];
int cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int ans=0;
	if(sum/n*n==sum)
	{
		int av=sum/n;
		for(int i=0;i<n;i++)
		 ans+=(abs(a[i]-av));
		cout<<ans/2<<endl;
	}
	else if(sum/n*n<sum)
	{
		sort(a,a+n,cmp);
		int av=sum/n;
		int i;
		for(i=0;i<sum%n;i++)
		 ans+=(abs(a[i]-(av+1)));
		for(i;i<n;i++)
		 ans+=(abs(a[i]-av));
		cout<<ans/2<<endl;
	}
	return 0;
}
