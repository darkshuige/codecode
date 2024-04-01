#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n%(m+1)==0)
		{
			printf("Second win\n");
		}
		else
		{
			printf("First win\n");
		}
	}
	return 0;
}
