#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int a[maxn];
signed main()
{
	int n; cin>>n;
	int ma=0;
	int l,r,ll=0,rr=0;
	int sum=0;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	l=0,r=0,ma=a[0],sum=a[0];
	while(1)
	{
		if(r==n-1 && l==n-1) break;
		sum+=a[++r];
		if(sum>ma)
		{
			ma=sum;
			ll=l;
			rr=r;
		}
		while(sum+a[r+1]>0 && r<=n-1)
		{
			r++;
			sum+=a[r+1];
			if(sum>ma)
			{
				ma=sum;
				ll=l;
				rr=r;
			}
		}
		sum-=a[l++];
		if(sum>ma)
		{
			ma=sum;
			ll=l;
			rr=r;
		}
	}
	if(ma>0)
	 cout<<ma<<" "<<ll<<" "<<rr<<endl;
	else
	 cout<<0<<" "<<0<<" "<<n-1<<endl;
	return 0;
} 