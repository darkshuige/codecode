#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cou.tie(0)
#define int long long
#define endl "\n"
using namespace std;
int a[20][20];
int flag[20];
int ma;
void dfs(int now,int sum)
{
	if(now==14)
	{
		ma=max(ma,now);
		return ;
	}
	for(int i=1;i<=13;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			dfs(now+1,sum+a[now][i]);
			flag[i]=0;
		}
	}
}
signed main()
{
	for(int i=1;i<=13;i++)
	 for(int j=1;j<=13;j++)
	  cin>>a[i][j];
	ma=0;
	memset(flag,0,sizeof flag);
	dfs(1,0);
	cout<<ma<<endl;
	return 0;
}