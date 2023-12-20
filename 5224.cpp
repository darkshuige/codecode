#include<iostream>
#include<stdio.h>
using namespace std;
double qiu(int n)
{
	int i;
	double sum=1;
	for(i=1;i<=n;i++)
	{
		sum*=i;
	}
	return sum;
}
int main()
{
	double sum=0;
	int t,i,n;
	int j;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		for(j=1;j<=n;j++)
		{
			sum=sum+1/qiu(j);
		}
		printf("%.4f\n",sum);
		sum=0;
	}
	return 0;
}
