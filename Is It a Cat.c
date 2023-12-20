#include<stdio.h>
int main()
{
	int n,i,j,k;
	char a;
	int flag1=0,flag2=0,flag3=0,flag4=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		flag1=0,flag2=0,flag3=0,flag4=0;
		scanf("%d",&j);
		getchar(); 
		scanf("%c",&a);
		if(a=='m' || a=='M')
		{
			flag1=1;	
		}
		else
		{
			printf("NO\n");
			continue;
		}
		if(flag1)
		{
			for(k=0;k<j-1;k++)
			{
				scanf("%c",&a);
				if((a=='m' || a=='M') && flag1 &&flag2==0 && flag3==0 && flag4==0)
				{
					continue;
				}
				else if((a=='e' || a=='E') && (flag1 && flag2==0 && flag3==0 && flag4==0))
				{
					flag1=0;
					flag2=1;
				}
				else if((a=='e' || a=='E') && flag2 && flag1==0 && flag3==0 &&flag4==0)
				{
					continue;
				}
				else if((a=='o' || a=='O') && (flag2 && flag3==0 &&flag4==0 && flag1==0))
				{
					flag2=0;
					flag3=1;
				}
				else if((a=='o' || a=='O') && flag3 && flag1==0 && flag2==0 && flag4==0)
				{
					continue;
				}
				else if((a=='w' || a=='W') && (flag3 && flag4==0 && flag1==0 && flag2==0))
				{
					flag3=0;
					flag4=1;
				}
				else if((a=='w' || a=='W') && flag4 &&flag1==0 && flag2==0 &&flag3==0)
				{
					continue;
				}
				else
				{
					printf("NO\n");
					break;
				}
			}
			getchar();	
			if(flag1==0 && flag2==0 && flag3==0 && flag4 && k==j-1)
			{
				printf("YES\n");
			}
		}
	}	
	return 0;
} 
