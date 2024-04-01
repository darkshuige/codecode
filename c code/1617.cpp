#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a[105]={0};
		int n,m;
		cin>>n>>m;
		int j;
		for(j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		if(a[j-1]<100)
		 a[j]=100;
		a[0]=0;
		int maxn=INT_MIN;
		for(j=0;j<=n;j++)
		{
			int sum=0;
			if(j+m+1>=n+1)
			{
				sum=100-a[j];
			}
			else
			{
				sum=(a[j+m+1]-1)-a[j];
			}
			if(sum>maxn) maxn=sum;
		}
		cout<<maxn<<endl;
	}
	return 0;
}
