#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a,b;
		int count=0;
		for(int i=1;(a=i*(i-1)/2)<n;i++)
		{
			b=(n-a)/i;
			if(b<=0)
			 break;
			if((n-a)%i==0)
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
