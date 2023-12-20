#include<bits/stdc++.h>
using namespace std;
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
const int maxn=100005;
int a[maxn]={0};
signed main()
{
	int n,h,k;
	cin>>n>>h>>k;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		int sum=(x/4)*y*3;
		if(x%4==0)
		 sum-=y;
		x%=4;
		for(int j=0;j<3;j++)
		{
			if(j==0)
			 x-=2;
			else
			 x-=1;
			if(x>0)
			 sum+=y;
		}
		a[i]=sum;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	 a[i]+=a[i-1];
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int x;
		cin>>x;
		int ans=0;
		int l=1,r=n;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if((x*k+h)<=a[mid])
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
				ans=mid;
			}
		}
		if(i!=0)
		 cout<<" ";
		cout<<ans;
	}
	return 0;	
} 
