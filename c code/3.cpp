#include<stdio.h>
void px(int a[],int n)
{
	int i,j,max,t;
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[max])
			{
				max=j;
			}
		}
		t=a[i];
		a[i]=a[max];
		a[max]=t;
	}
}
int main()
{
	int i,t,k,j,p[5005]={0},sum,max=0,jia[5005],m;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		sum=0;	
		m=0;
		for(j=0;j<=5000;j++)
		 p[j]=0;
		 jia[j]=0;
		scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&p[j]);
			if(p[j]==0)
			{
				px(p,j);
				sum=sum+p[0];
				p[0]=0;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
