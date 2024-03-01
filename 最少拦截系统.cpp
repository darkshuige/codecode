#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int a[maxn],f[maxn];
signed main()
{
	int n;
	while(cin>>n)
	{
		int ans=0;
		memset(f,0,sizeof f);
		for(int i=0;i<n;i++) cin>>a[i],f[i]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(a[j]<a[i])
				{
					f[i]=max(f[i],f[j]+1);
				}
			}
			ans=max(ans,f[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}