#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int ws(int a)
{
	int i;
	int sum=1;
	for(i=2;i<a/2+1;i++)
	{
		if(a%i==0)
		 sum+=i;
	}
	if(sum==a)
	 return 1;
	else
	 return 0;
}
int main()
{
	int l,r;
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int count=0;
		scanf("%d %d",&l,&r);
		int j;
		for(j=l;j<=r;j++)
		 if(ws(j))
		  count++;
		printf("%d\n",count);
	}
	
	return 0;
}
