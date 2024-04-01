#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	long long n,m,k,sum=1;
	cin>>n>>m;
	while(n)
	{
		if(m==0)
		{
			cout<<"1"<<endl;
		}
		else
		{
			for(k=1;k<=m;k++)
			{
				sum=(sum*(n-m+k))/k;
			}
			cout<<sum<<endl;
		}
		sum=1;
		cin>>n>>m;	
	}
	return 0;
}
