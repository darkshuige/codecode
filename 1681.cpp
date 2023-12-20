#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=n;i>=1;i--)
		 printf("%d\n",i);
		for(int i=2;i<=n;i++)
		 printf("%d\n",i);
	}
	return 0;
}
