#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int a[maxn]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i)
		{
			a[j]++;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i]*a[n-i];
	}
	cout<<sum<<endl;
	return 0;
}
