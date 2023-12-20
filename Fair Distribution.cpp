#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int max=1e7;
		scanf("%d %d",&n,&m);
		if(m%n==0)
		{
			printf("0\n");
		}
		else if(n>m)
		{
			printf("%d\n",n-m);
		}
		else
		{
			int j;
			for(j=0;j<n;j++)
			{
				int k;
				k=m%(n-j);
				if(abs(k-(n-j))+j<max)
				 max=abs(k-(n-j))+j;
				if(j>=max)
				{
					break;
				}
			}
			printf("%d\n",max);
		}
	}
	return 0;
} 
