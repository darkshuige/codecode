#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
//int find(int a[],int l,int r,int x)
//{
//	int mid,flag=0;
//	while(l<=r)
//	{
//		mid=(l+r)/2;
//		if(a[mid]<x)
//		{
//			l=mid+1;
//		}
//		else if(a[mid]>x)
//		{
//			r=mid-1;
//		}
//		if(a[mid]==x)
//		{
//			flag=1;
//			break;
//		}
//	}
//	if(flag)
//	{
//		return mid;
//	}
//	else
//	{
//		return -1;
//	}
//}
int main()
{
	int n,m,i,a[1005]={0},count=1,j,b,flag=0;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		 cin>>a[i];
		sort(a,a+n);
		printf("CASE# %d:\n",count++);
		for(i=0;i<m;i++)
		{
			cin>>b;
			flag=0;
			for(j=0;j<n;j++)
			 if(a[j]==b)
			 {
			 	flag=1;
			 	break;
			 }
			if(flag)
		   	 printf("%d found at %d\n",b,j+1);
		   	else
			 printf("%d not found\n",b);
		}	
	}
	return 0;
} 
