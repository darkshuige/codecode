#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int dp[50005]={0};
		int vv[50005]={0};
		int ww[50005]={0};
		int num=1;//拆分计数
		for(int i=1;i<=n;i++)
		{
			int v,w,s;
			cin>>v>>w>>s;//体积，价值，数量
			for(int j=1;j<=s;j<<=1)
			{
				vv[num]=v*j;
				ww[num++]=w*j;
				s-=j;
			}
			if(s)// 剩余
			{
				vv[num]=s*v;
				ww[num++]=s*w;
			}
		}
		for(int i=1;i<num;i++)
		{
			for(int j=m;j>=vv[i];j--)
			{
				dp[j]=max(dp[j],dp[j-vv[i]]+ww[i]);
			}
		}
		cout<<dp[m]<<endl;
	}
	return 0;
} 
