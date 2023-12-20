#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000050;
const int mod=998244353;
int ans,n;
int vis[20];
int a[20];
int sb;
map<int,int>mp;
map<int,int>vss;
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		 ans=(ans*a);
		a=(a*a);
		b>>=1;
	}
	return ans;
}
void dfs(int cnt,int sum)
{
	if(cnt==n)
	{
		if(mp.count(sum)==0 && sqrt(sum)==(int)(sqrt(sum)))
		{
			mp[sum]=1;
			ans++;
		}
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]==1) continue;
		int op=sum+ksm(10,n-cnt-1)*a[i];
		if(vss[op]>sb) continue;
		vss[op]++;
		vis[i]=1;
		dfs(cnt+1,sum+ksm(10,n-cnt-1)*a[i]);
		vis[i]=0;
		vss[op]--;
	}
}
signed main()
{
	jiasu;
	cin>>n;
	string s;
	cin>>s;
	sb=0;
	for(int i=0;i<n;i++)
	{
		a[i]=s[i]-'0';
		if(a[i]==0)
		 sb++;
	}
	ans=0;
	memset(vis,0,sizeof vis);
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
