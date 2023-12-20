#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
	int i,j,n,a[8000][255]={0};

int main()
{
	::a[1][1]=1;
	::a[2][1]=1;
	for(i=3;i<8000;i++)
	{
		for(j=1;j<254;j++)
		{
			::a[i][j]=::a[i][j]+::a[i-2][j]+::a[i-1][j];
			::a[i][j+1]=::a[i][j+1]+::a[i][j]/100000000;
			::a[i][j]=::a[i][j]%100000000;	
		}	
	}
	while(scanf("%d",&n)!=EOF)
	{
		for(i=254;;i--)
		{
			if(::a[n][i]!=0)
			{
				break;
			}
		}
		printf("%d",::a[n][i]);
		for(i=i-1;i>=1;i--)
		{
			printf("%.8d",::a[n][i]);
		}
		printf("\n");
	}	
	return 0;
}
