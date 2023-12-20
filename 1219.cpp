#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int n,m,sum=0;
		cin>>n>>m;
		int j=1,k=1;
		for(j;j<=m;j++)
		{
			sum+=k;
			if(k==n)
			 k=1;
			else
			 k++;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
