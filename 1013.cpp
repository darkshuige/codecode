#include<iostream>
#include<stdio.h>
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;
}
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int gys(int a,int b)
{
	int t=a%b;
	while(t)
	{
		a=b;
		b=t;
		t=a%b;
	}
	return b;
}
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	while(a && b)
	{
		if(max(a,b)==b)
		 swap(&a,&b);
		cout<<gys(a,b)<<endl;
		scanf("%d %d",&a,&b);
	}
	return 0;
}
