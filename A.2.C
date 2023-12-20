#include<stdio.h>
int main()
{
	int n,i,j,k;
	char a[55];
	int flag1=0,flag2=0,flag3=0,flag4=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		flag1=0,flag2=0,flag3=0,flag4=0;
		scanf("%d",&j);
		scanf("%s",a);
		if(a[0]=='m' || a[0]=='M')
		{
			flag1=1;	
		}
		else
		{
			printf("NO\n");
			flag1=0,flag2=0,flag3=0,flag4=0;
			continue;
		}
		if(flag1)
		{
			for(k=1;k<j;k++)
			{
				if((a[k]=='m' || a[k]=='M') && flag1 && flag2==0 && flag3==0 && flag4==0)
				{
				}
				else if((a[k]=='e' || a[k]=='E') && (flag1 && flag2==0 && flag3==0 && flag4==0))
				{
					flag1=0;
					flag2=1;
				}
				else if((a[k]=='e' || a[k]=='E') && flag2 && flag1==0 && flag3==0 &&flag4==0)
				{
				}
				else if((a[k]=='o' || a[k]=='O') && (flag2 && flag3==0 &&flag4==0 && flag1==0))
				{
					flag2=0;
					flag3=1;
				}
				else if((a[k]=='o' || a[k]=='O') && flag3 && flag1==0 && flag2==0 && flag4==0)
				{
				}
				else if((a[k]=='w' || a[k]=='W') && (flag3 && flag4==0 && flag1==0 && flag2==0))
				{
					flag3=0;
					flag4=1;
				}
				else if((a[k]=='w' || a[k]=='W') && flag4 &&flag1==0 && flag2==0 &&flag3==0)
				{
				}
				else
				{
					flag1=0;
					printf("NO\n");
					flag1=0,flag2=0,flag3=0,flag4=0;
					break;
				}	
			}
			if(flag1==0 && flag2==0 && flag3==0 && flag4)
			{
				printf("YES\n");
			}	
		}	
	}
	return 0;
}
