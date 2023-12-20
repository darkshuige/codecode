#include<stdio.h>
#include<math.h>
const int max=1e+5;
int s[1000006]={0};
void ss()
{
	s[0]=s[1]=1;
	int i,j;
	for(i=2;i<=max;i++)
	{
		if(!s[i])
		{
			for(j=i+i;j<=max;j=j+i)
			{
				s[j]=1;
			}
		}
	}
}
int main()
{
	int n,i;
	long long a,b;
	ss();
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a);
		b=sqrt(a);
		if(b*b==a && s[b]==0 && b>1)
		 printf("YES\n");
		else
		 printf("NO\n");
	}
	return 0;
}
