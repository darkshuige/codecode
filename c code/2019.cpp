#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	while(scanf("%d",&t)!=EOF)
	{
		for(int i=0;i<t;i++)
		{
			long long a,b;
			scanf("%lld %lld",&a,&b);
			printf("%lld\n",abs(a-b));
		}	
	}
	
	return 0;
}
