#include<stdio.h>
int A[100005]={0};
int main()
{
	int n,i,t,j,a,b;
	long long sum,total=0;
	while(scanf("%d",&n)!=EOF)
	{
		total=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&A[i]);
			total+=A[i];
		}
		scanf("%d",&t);
		for(j=0;j<t;j++)
		{
			sum=0;
			scanf("%d %d",&a,&b);
			if(a==1 && b==1)
			 printf("%lld\n",total);
			else
			{
				while(a<=n)
				{
					sum+=A[a];
					a+=b;
				}
				printf("%lld\n",sum);	
			}
			
		}
	}
	
	return 0;	
} 
