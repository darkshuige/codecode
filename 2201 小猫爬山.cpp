#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(fasle),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;
int a[maxn],n,w,ans,cnt,d[maxn];
void dfs(int p)
{
	if(p==n)
	{
		ans=min(ans,cnt);
		return ;
	}
	if(cnt>ans) return ;
	for(int i=0;i<cnt;i++)
	{
		if(d[i]+a[p]<w)
		{
			d[i]+=a[p];
			dfs(p+1);
			d[i]-=a[p];
		}
	}
	d[cnt++]+=a[p];
	dfs(p+1);
	d[--cnt]-=a[p];
}
signed main()
{
	cin>>n>>w;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	ans=INT_MAX,cnt=0;
	dfs(0);
	cout<<ans<<endl;
	return 0;
} 
