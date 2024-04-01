#include<iostream>
#include<stdio.h>
#include<string.h> 
using namespace std;
int main()
{
	int t,i,n,m,j,l;
	char b;
	char zzp[1005];
	cin>>t;
	for(i=0;i<t;i++)
	{
		int a[6]={0},count=0,flag=1,sum=0;
		cin>>n;
		getchar();
		for(j=0;j<n;j++)
		{
			scanf("%c",&b);
			getchar();
			if(b=='W')
			 a[1]++;
			else if(b=='U')
			 a[2]++;
			else if(b=='B')
			 a[3]++;
			else if(b=='G')
			 a[4]++;
			else if(b=='R')
			 a[5]++;
		}
		cin>>m;
		for(j=0;j<m;j++)
		{
			scanf("%s",&zzp);
			for(l=0;l<strlen(zzp);l++)
			{
				if(zzp[l]=='W')
				{
					a[1]--;
					if(a[1]<0)
					{
						flag=0;
					}
				}
				else if(zzp[l]=='U')
				{
					a[2]--;
					if(a[2]<0)
					{
						flag=0;
					}
				}
				else if(zzp[l]=='B')
				{
					a[3]--;
					if(a[3]<0)
					{
						flag=0;
					}
				}
				else if(zzp[l]=='G')
				{
					a[4]--;
					if(a[4]<0)
					{
						flag=0;
					}
				}
				else if(zzp[l]=='R')
				{
					a[5]--;
					if(a[5]<0)
					{
						flag=0;
					}
				}
				else if(zzp[l]=='O')
				{
					count++;
				}
			}	
		}
		for(j=1;j<=5;j++)
		 sum+=a[j];
		if(sum>=count && flag)
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
