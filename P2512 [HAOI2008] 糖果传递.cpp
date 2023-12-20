#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
int c[maxn]={0},a[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int b=sum/n;
	for(int i=1;i<=n;i++)
	 c[i]=c[i-1]+a[i-1]-b;
	sort(c+1,c+1+n);
	sum=0;
	for(int i=1;i<=n;i++)
	 sum+=abs(c[i]-c[n/2+1]);
	cout<<sum<<endl;
	return 0;
}
