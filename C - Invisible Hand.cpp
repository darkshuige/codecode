#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=200005;
int b[maxn],a[maxn];
int n,m;
int cmp(int a,int b)
{
	return a>b;
}
int fa(int mid)
{
	int i=1;
	while(i<=n)
	{
		if(mid>=a[i])
		 i++;
		else
		 break;
	}
	return i-1;		
}
int fb(int mid)
{
	int i=1;
	while(i<=m)
	{
		if(mid<=b[i])
		 i++;
		else
		 break;
	}
	return i-1;
}
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int i=1;i<=m;i++)
	 cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m,cmp);
	int l=1,r=1000000005;
	int ans=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(fa(mid)>=fb(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
