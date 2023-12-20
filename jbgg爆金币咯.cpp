#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int i,t,n,m,x,j,l;
	int a[10],b[10];
	bool A[2005],B[2005];
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>m>>x;
		for(j=0;j<=x;j++)
		{
			A[j]=0;
			B[j]=0;
		}
		for(j=0;j<n;j++)
		 cin>>a[j];
		for(j=0;j<m;j++)
		 cin>>b[j];
		for(l=1;l<=x;l++)
		{
			for(j=0;j<n;j++)
			{
				if(l-a[j]<=0 || B[l-a[j]]==0)
				{
					A[l]=1;
				}
			}
			for(j=0;j<m;j++)
			{
				if(l-b[j]<=0 || A[l-b[j]]==0)
				{
					B[l]=1;
				}
			}
		}
		if (A[x]) 
		{
      		printf("AsindE\n");
    	} 
		else 
		{
    	 	printf("slwang\n");
		}
	}
	return 0;
}
