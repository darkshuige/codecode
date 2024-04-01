#include<stdio.h>
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		double ans=a*0.7+b*0.3;
		if(ans>=90)
		 printf("A\n");
		else if(ans>=80)
		 printf("B\n");
		else if(ans>=70)
		 printf("C\n");
		else
		 printf("D\n");
	}
	return 0;
}
