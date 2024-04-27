#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200005;
const int mod=1e9+7;
int pre[2][maxn];
int a[maxn];
signed main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	int ans=0;
	for(int bt=0;bt<=20;bt++)
	{
		memset(pre,0,sizeof pre);
		for(int i=1;i<=n;i++)
		{
			pre[0][i]=pre[0][i-1];
			pre[1][i]=pre[1][i-1];
			if(a[i] & ((int)1<<bt))
			{
				ans=(ans+(pre[0][i-1]*(n-i+1))%mod*((int)1<<bt)%mod)%mod;
				pre[1][i]=(pre[1][i]+i)%mod;
			}
			else
			{
				ans=(ans+(pre[1][i-1]*(n-i+1))%mod*((int)1<<bt)%mod)%mod;
				pre[0][i]=(pre[0][i]+i)%mod;
			}
		}
	}
	cout<<ans*(int)2%mod<<endl;
	return 0;
}