#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int a[12][12];
		for(int i=1;i<=11;i++)
		{
			for(int j=1;j<=11;j++)
			{
				a[i][j]=1;
			}
		}
		int maxn=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=n;j++)
			{
				a[i][j]=a[i-1][j]+a[i][j-1];
				if(a[i][j]>maxn)
				 maxn=a[i][j];
			}
		}
		printf("%d\n",maxn);
	}
	return 0;
}
