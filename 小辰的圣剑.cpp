#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200005;
int a[maxn],b[maxn];
int aa[maxn],bb[maxn];
signed main()
{
	jiasu;
	int n,m,u;
	cin>>n>>m>>u;
	memset(aa,0,sizeof aa);memset(bb,0,sizeof bb);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		aa[i]=aa[i-1]+a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		bb[i]=bb[i-1]+b[i];
	} 
	int l=1,r=0,ans=0;
	int ff=1;
	while(1)
	{
		if(ff==0) break;
		ff=0;
		if(r<n) r++,ff=1;
		int flag=1;
		while(flag && l<r)
		{
			flag=0;
			int sum1=0,sum2=0;
			sum1=aa[r]-aa[l-1];sum2=bb[r]-bb[l-1];
			if(sum1>m || sum2>u)
			{
				flag=1;
				l++;
				ff=1;
			}
		}
		if(l==r && (a[l]>m || b[l]>u))
		{
			
		}
		else
		{
			ans=max(ans,r-l+1);
		}
		if(r==n && r==l) break;
	}
	cout<<ans<<endl; 
	return 0;
} 
