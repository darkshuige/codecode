#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn];
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	int ma,mi;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(b+1,b+1+m);
	cin>>mi>>ma;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		int ans1,ans2;
		int ans;
		int l=1,r=m,flag=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(a[i]*b[mid]>=mi && a[i]*b[mid]<=ma)
			{
				ans=mid;
				r=mid-1;
				flag=1;
			}
			else
			{
				if(a[i]>=0)
				{
					if(a[i]*b[mid]<mi) l=mid+1;
					else r=mid-1;	
				}
				else
				{
					if(a[i]*b[mid]<mi) r=mid-1;
					else l=mid+1;
				}
			}
		}
		ans1=ans;
		l=1,r=m;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(a[i]*b[mid]>=mi && a[i]*b[mid]<=ma)
			{
				ans=mid;
				l=mid+1;
				flag=1;
			}
			else
			{
				if(a[i]>=0)
				{
					if(a[i]*b[mid]<mi) l=mid+1;
					else r=mid-1;	
				}
				else
				{
					if(a[i]*b[mid]<mi) r=mid-1;
					else l=mid+1;
				}
			}
		}
		ans2=ans;
		if(flag)
		 res+=ans2-ans1+1;	
	}
	cout<<res<<endl;
	return 0;
}