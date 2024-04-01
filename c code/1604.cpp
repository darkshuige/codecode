#include<bits/stdc++.h>
using namespace std;
char a[200],b[200];
int main()
{
	while(scanf("%s %s",&a,&b)!=EOF)
	{
		long long sum=0;
		for(int i=0;i<strlen(a);i++)
		{
			sum+=a[i]-48;
		}
		for(int i=0;i<strlen(b);i++)
		{
			sum+=b[i]-48;
		}
		printf("%lld\n",sum);	
	}
	
}
