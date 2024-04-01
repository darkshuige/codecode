#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	int i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		double sum=0;
		int n;
		cin>>n;
		int flag=1;
		int j;
		for(j=1;j<=n;j++)
		{
			sum+=(1.0/j)*flag;
			flag=-flag;
		}
		printf("%.3f\n",sum);
	}
	return 0;
} 
