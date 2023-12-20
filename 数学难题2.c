#include<stdio.h>
int main()
{
	int t,i;
	long long x;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&x);
		if(x==0)
		{
			printf("0\n");
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
