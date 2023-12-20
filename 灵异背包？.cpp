#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
int a[maxn];
signed main()
{
	jiasu;
	int n;
	int cnt=0;
	int sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%2==1)
		 cnt++;
		sum+=a[i];
	}
	if(cnt%2==0)
	 cout<<sum<<endl;
	else
	{
		sort(a,a+n);
		int pos=0;
		while(a[pos]%2==0) pos++;
		sum-=a[pos];
	}
	cout<<sum<<endl;
	return 0;
}
