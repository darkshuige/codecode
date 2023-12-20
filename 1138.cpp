#include<iostream>
#include<stdio.h>
using namespace std;
int t[1020][1020];
int main()
{
	int k,n,j;
	for(k=0;k<1020;k++)
	{
		for(j=0;j<1020;j++)
		{
			if(k==0)
			{
				t[k][j]=j;
			}
			else if(j==1)
			{
				t[k][j]=1;
			}
			else
			{
				t[k][j]=(t[k-1][j]+t[k][j-1])%100007;
				t[k][j]%=100007;
			}
		}
	}
	int a,b; 
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		printf("%d\n",t[a][b]);
	}
	return 0;
}
