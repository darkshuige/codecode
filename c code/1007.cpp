#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	double n,i,sum,a;
	cin>>n;
	while(n!=0)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a;
			sum+=a;
		}
		printf("%.2f\n",sum/n);
		cin>>n;
	}
	return 0;
}
