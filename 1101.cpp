#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,i,j,count=0;
	char list[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while(scanf("%d",&n)!=EOF)
	{
		if(count!=0)
		{
			cout<<endl;
		}
		count++;
		char a[15][15]={0};
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]=='.')
				{
					for(int k=0;k<26;k++)
					{
						if(a[i-1][j]==list[k] && i-1>=0)
						 continue;
						if(a[i+1][j]==list[k] && i+1<n)
						 continue;
						if(a[i][j+1]==list[k] && j+1<n)
						 continue;
						if(a[i][j-1]==list[k] && j-1>=0)
						 continue;
						a[i][j]=list[k];
						 break;
					}
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			 cout<<a[i][j];
			cout<<endl;
		}
	}
	return 0;
}
