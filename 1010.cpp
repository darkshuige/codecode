#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,i;
	double n;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		printf("%.0f\n",(n*n+n+2)/2);
	}
	return 0;
} 
