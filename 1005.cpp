#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	double n,m,a,l,r;
	while(scanf("%lf %lf %lf",&n,&m,&a)!=EOF)
	{
		if((n/a)!=(int)(n/a))
		{
			l=(int)(n/a+1);
		}
		else
		{
			l=(n/a);
		}
		if((m/a)!=(int)(m/a))
		{
			r=(int)(m/a+1);
		}
		else
		{
			r=(m/a);
		}
		printf("%.0f\n",l*r);	
	}
	return 0;
}
