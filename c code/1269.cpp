#include<stdio.h>
main()
{
int r;
while(scanf("%d",&r)!=EOF)
{
	double df,sum1=0,sum2=0;
	char a;
	double f;
	int i,flag=1; 
	for(i=1;i<=r;i++)
	{
		scanf("%lf %c",&f,&a);
		switch(a)
		{
			case 'A':df=4.0;sum1=sum1+(f*df);sum2=sum2+f;break;
			case 'B':df=3.0;sum1=sum1+(f*df);sum2=sum2+f;break;
			case 'C':df=2.0;sum1=sum1+(f*df);sum2=sum2+f;break;
			case 'D':df=1.3;sum1=sum1+(f*df);sum2=sum2+f;break;
			case 'F':sum2=sum2+f;break;
		}
	}
	if(sum2==0)
	{
		printf("0.00\n");
	}
	else
	{
		printf("%.2lf\n",sum1/sum2);
	}
	sum1=0;
	sum2=0;
	flag=1;
}
}
