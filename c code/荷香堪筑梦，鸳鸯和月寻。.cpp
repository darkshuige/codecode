#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1050;
char a[maxn][maxn];
int dp[maxn][maxn];
signed main()
{
	int n,m,x;
	cin>>n>>m>>x;
	int pos;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	 {
	 	cin>>a[i][j];
		if(a[i][j]=='a')
		 pos=j;	
	 }
	dp[n][pos]=1;
	for(int i=n-1;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!='*')
			{
				for(int k=j;k<=j+x && k<=m;k++)
				 dp[i][j]=max(dp[i+1][k],dp[i][j]);
				for(int k=j;k>=1 && k>=j-x;k--)
				 dp[i][j]=max(dp[i+1][k],dp[i][j]);	
			}	
		}	
	}	
	for(int i=1;i<=m;i++)
	 if(dp[1][i]==1)
	 {
	 	cout<<"yes"<<endl;
	 	return 0;
	 }
	cout<<"no"<<endl;
	return 0;
}
