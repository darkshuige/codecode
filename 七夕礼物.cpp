#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=200005;
int a[maxn];
signed main()
{
	jiasu;
	int n,k;
	cin>>n>>k;
	int r=INT_MIN;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>r)
		 r=a[i];
	}
	int flag=0;
	int l=1;
	while(l<=r)
	{
		flag=0;
		int sum=0;
		int mid=(l+r)/2;
		for(int i=0;i<n;i++)
		{
			sum+=a[i]/mid;
			if(sum>=k)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<r<<endl;
	return 0;
} 
