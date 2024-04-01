#include<stdio.h>
char s[2500000];
int main()
{
	int t,i,n,k,j,start,end,flag=0,l,gs[2]={0},f,k1,flag2=0;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		f=0,flag2=0;
		flag=0,gs[0]=0,gs[1]=0;
		scanf("%d %d",&n,&k);
		if(k>=n)
		{
			if(k%2==n%2)
			{
				k=n;
			}
			else
			{
				k=n+1;
			}
		}
		k1=k;
		scanf("%s",&s);
//		if(n>1)
//		{
			for(j=0;j<n;j++)
			{
				if(s[j]=='1')
				{
					gs[1]++;
				}
			}
			gs[0]=n-gs[1];
			while(k>=gs[f] || k>=gs[!f])
			{
				if((k==gs[f] || k==gs[!f]) && k%2==0 && k)
				{
					for(l=0;l<n;l++)
					 printf("1");
					printf("\n");
					flag2=1;
					break;
				}
				else
				{
					k--;
					f=!f;
				}
			}
//		}	
		k=k1;
		if(flag2==0)
		{
		for(j=0;j<n && k;j++)
		{
			if(s[j]=='0' && flag==0)
			{
				flag=1;
			}
			if(s[j]=='1' && flag==1)
			{
				flag=0;
				k--;
			}
			if(s[j]=='0' && flag==1 && k)
			{
				s[j]='1';
			}
		}
		if(k)
		{
			if(k%2==0)
			{
				printf("%s\n",s);
			}
			else
			{
				if(n<2 || k==1)
				{
					s[n-1]='0';	
				}
				printf("%s\n",s);
			}
		}
		else
		{
			printf("%s\n",s);
		}
		}	
	}
	return 0;
} 
