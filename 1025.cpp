#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;//2+3+8.4
int main()
{
	int t,i,n,j;
	double a,b,sum;
	cin>>t;
	for(i=0;i<t;i++)
	{
		sum=0;
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>a>>b;
			sum=sum+((floor(a*b*10+0.5))/10);
		}
		printf("%.1f\n",sum);
	}
	return 0;
} 
