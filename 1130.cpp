#include<iostream>
#include<stdio.h> 
using namespace std;
int main()
{
	int a[30]={0};
	a[1]=1;
	a[2]=2;
	int i;
	for(i=3;i<=25;i++)
	{
		a[i]=a[i-2]+a[i-1];
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",a[n]);
	}
	return 0;
}
