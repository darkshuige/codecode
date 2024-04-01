#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1 || n%2==0)
		{
			printf("2^? mod %d = 1\n",n);
		}
		else
		{
			int i=1,t=2;
			while(t!=1)
			{
				t<<=1;
				t=t%n;
				i++;
			}
			printf("2^%d mod %d = 1\n",i,n);
		}
	}
	return 0;
}
