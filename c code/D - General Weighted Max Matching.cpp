#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;
int match[maxn],d[maxn][maxn];
int n,ans,sum; 
void dfs(int now)
{
	if(now==n+1)
	{
		ans=max(ans,sum);
		return ;
	}
	if(match[now])//如果这个已经匹配过了，就找下一个 
	{
		dfs(now+1);
		return ;//这个数就到此为止了 
	}
	for(int i=now+1;i<=n;i++)
	{
		if(match[i])
		 continue;
		match[now]=i;
		match[i]=now;
		sum+=d[now][i];//改了然后加上去dfs 
		dfs(now+1);
		match[now]=match[i]=0;
		sum-=d[now][i];//回溯
	}
	dfs(now+1);//当前数不匹配直接匹配下一个 
}
signed main()
{
	jiasu;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cin>>d[i][j];
		}
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
