#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int p=1;
		int sum=2;
		while(sum<=n)
		{
			p++;
			sum*=2;
		}
		p--;
		sum/=2;
		while(n%sum!=0)
		{
			p--;
			sum/=2;
		}
		printf("%d %d\n",n/sum,p);
	}
	return 0;
}
