#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int main()
{
	double a,b;
	double x;
	while(cin>>a>>b)
	{
		double s=0;
		double x;
		x=(a-b)/a;
		s=1.0/2.0*a*pow(x,2)-1.0/3.0*a*pow(x,3)-1.0/2.0*b*pow(x,2);
		s=abs(s);
		printf("%.6f\n",s);
	}
	
	return 0;
} 
