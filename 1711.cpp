#include<bits/stdc++.h>
using namespace std;
int n,m,a[30],ans;
void dfs(int ok,int index)
{
	if(ok==0)
	{
		ans++;
		return;
	}
	else if(ok<0 || index>n)
	{
		return;
	}
	else
	{
		dfs(ok-a[index],index+1);
		dfs(ok,index+1);
	}
}
int main()
{
	while(cin>>n>>m)
	{
		ans=0;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		dfs(m,1);
		cout<<ans<<endl;
	}
	return 0;
}
