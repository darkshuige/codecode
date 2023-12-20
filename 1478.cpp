#include <stdio.h>
int a[1500];
int main()
{
	int n,t,i,r,h1,h2,f1,f2,t1,t2,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		m=0;
		for(i=0;i<=1500;i++) a[i]=0;
		while(n--)
		{
			scanf("%d %d:%d %d:%d",&r,&h1,&f1,&h2,&f2);
			t1=h1*60+f1,t2=h2*60+f2;
			for(i=t1;i<t2;i++)
			 a[i]+=r;
		}
		for(i=0;i<=1500;i++)
		{
			if(a[i]>m)
			 m=a[i];
		}
		printf("%d\n",m);
	}
	return 0;
}
