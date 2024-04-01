#include<stdio.h>
long long hws(long long a)
{
	long long b=a;
	long long x=0;
	while(b)
	{
		x=x*10+b%10;
		b=b/10;
	}
	return x;
}
int main()
{
	long long a;
	while(scanf("%lld",&a)!=EOF)
	{
		int count=0;
		while(a!=hws(a) && count<=20)
		{
			a+=hws(a);
			count++;
		}
		if(count>20)
		{
			printf("impossible\n");
		}
		else 
		 printf("%d %lld\n",count,a);
	}
	return 0;
}
