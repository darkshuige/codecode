#include<bits/stdc++.h>
using namespace std;
long long cmp(const long long a,const long long b)
{
	return a>b;
}
int main()
{
	long long n,k;
	while(cin>>n>>k)
	{
		char s[100005];
		scanf("%s",&s);
		long long a[30]={0};
		int count=0;
		for(int i=0;i<n;i++)
		{
			a[(long long)(s[i])-65]++;
			count++;
		}
		sort(a,a+30,cmp);
		int i=0;
		long long sum=0;
		while(k && i<count)
		{
			if(k>a[i])
			{
				sum+=a[i]*a[i];
				k-=a[i];
				i++;
			}
			else
			{
				sum+=k*k;
				k=0;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
