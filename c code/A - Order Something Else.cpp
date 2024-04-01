#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
signed main()
{
	int n,p,q;
	cin>>n>>p>>q;
	int a[105];
	for(int i=0;i<n;i++)
	 cin>>a[i];
	sort(a,a+n);
	int sum1=p,sum2=a[0]+q;
	if(sum1<sum2)
	 cout<<sum1<<endl;
	else 
	 cout<<sum2<<endl;
	return 0;
} 
