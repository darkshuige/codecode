#include<stdio.h>
#include<ctype.h>
int main()
{
	int a[123]={0};
	char b;
	int i,j,k,n,l,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		sum=0;
		for(l=0;l<=122;l++)
		 a[l]=0;
		scanf("%d %d",&j,&k);
		getchar();
		for(l=0;l<j;l++)
		{
			b=getchar();
			a[toascii(b)]++;
		}
		for(l=65;l<=90;l++)
		{
			while(a[l] && a[l+32])
			{
				a[l]--;
				a[l+32]--;
				sum++;
			}
		}
		for(l=65;l<=90;l++)
		{
			while(a[l]>=2 && k)
			{
				a[l]=a[l]-2;
				k--;
				sum++;
			}
		}
		for(l=97;l<=122;l++)
		{
			while(a[l]>=2 && k)
			{
				a[l]=a[l]-2;
				k--;
				sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
