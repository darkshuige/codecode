#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int a[maxn],f[maxn];
signed main()
{
	jiasu;
	int n;
	while(cin>>n)
	{
		memset(f,0,sizeof f);
		int ans=0;
		if(n==0) break;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			f[i]=a[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(a[i]>a[j])
				{
					f[i]=max(f[i],f[j]+a[i]);
				}
			}
			ans=max(ans,f[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}