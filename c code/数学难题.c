#include<stdio.h>
#include<math.h>
int main()
{
	int t,i;
	double x;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lf",&x);
		if(x==0)
		{
			printf("0\n");
		}
		else if(x>1)
		{
			if(log(x+1)/log(2)==(int)(log(x+1)/log(2)))
			{
				printf("0\n");
			}
			else
			{
				printf("-1\n");
			}
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
