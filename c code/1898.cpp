#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[2010]={0};
		int dp1[2010];
		int dp2[2010];
		int res=0;
		for(int i=0;i<n;i++)
		 cin>>a[i];
		for(int i=n-1;i>=0;i--)
		{
			dp1[i]=1;
			dp2[i]=1;
			for(int j=n-1;j>i;j--)
			{
				if(a[j]>a[i])
				{
					dp1[i]=max(dp1[i],dp1[j]+1);
				}
				if(a[j]<a[i])
				{
					dp2[i]=max(dp2[i],dp2[j]+1);
				}
			}
			res=max(res,dp1[i]+dp2[i]-1);
		}
		cout<<res<<endl;
	}
	return 0;
} 
