#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,k,l;
	char a[55]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=50;j++)
		 a[j]=0;
		scanf("%d",&k);
		scanf("%s",&a);
		for(j=0;j<k;j++)
		{
			if(toupper(a[j+1])==toupper(a[j]))
			{
				for(l=j;l<k;l++)
				{
					a[l]=a[l+1];
				}
				k--;
				j--;
			}
		}	
		if(toupper(a[0])=='M' && toupper(a[1])=='E' && toupper(a[2])=='O' && toupper(a[3])=='W' && strlen(a)==4)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
