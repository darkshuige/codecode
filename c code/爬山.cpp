#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=100005;
int a[maxn],n;
int f(int mid)
{
	int sum=0;
	int pos=0;
	while(a[pos]<=mid)
	 pos++;
	for(int i=pos;i<n;i++)
	 sum+=a[i]-mid;
	sum*=2;
	return sum;
}
signed main()
{
	jiasu;
	int p;
	cin>>n>>p;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum*=2;
	if(sum<p)
	{
		cout<<-1<<endl;
		return 0;
	}
	sort(a,a+n);
	int l=0,r=a[n-1];
	int ans=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(f(mid)>=p)
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
