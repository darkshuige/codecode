#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
int a[200005];
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,m,k;
		cin>>n>>m>>k;
		for(int j=1;j<=n;j++)
		 cin>>a[j];
		int B=2*sqrt(n+1)+5;
		int ans=2e9;
		for(int c=max((long long)1,m-B);c<=min(m+B,n);c++)
		{
			for(int j=1;j<=c;j++)
			{
				int neq=0;
				for(int l=j;l<=n;l+=c)
				 if(a[l]!=k)
				  neq++;
				ans=min(ans,neq+abs(c-m));
			}
		}
		cout<<ans<<endl;
	}
	return 0;	
} 
