#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[105][105];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			 cin>>a[i][j];
		}
		int sum1=0,sum2=0;
		for(int i=0;i<n;i++)
		{
			sum1+=a[i][i];
			sum2+=a[i][n-i-1];
		}
		cout<<sum1<<endl<<sum2<<endl;		
	}
	return 0;
} 
