#include<stdio.h>
int main()
{
	long long sum=0;
	int t,i,n,j;
	int a[9]={0};
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		sum=0;
		scanf("%d",&n);
		scanf("%d",&a[0]);
		sum=sum+a[0];
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			sum=sum*a[j]>sum+a[j]?sum*a[j]:sum+a[j];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
