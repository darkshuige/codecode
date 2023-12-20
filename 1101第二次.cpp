#include<iostream>
#include<stdio.h>
using namespace std;
char max(char a[],int n)
{
	int i;
	char m='.';
	for(i=0;i<n;i++)
	{
		if(a[i]>m)
		 m=a[i];
	}
	return m+1;
}
int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		char a[11][11]={0};
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				char b;
				cin>>b;
			}		
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				char p[4]={0};
				p[0]=a[i-1][j];p[1]=a[i+1][j];p[2]=a[i][j-1];p[3]=a[i][j+1];
				if(a[i-1][j]=='.' && a[i+1][j]=='.' && a[i][j-1]=='.' && a[i][j+1]=='.')
				{
					a[i][j]='A';
				}
				else
				{
					a[i][j]=max(p,4);
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
