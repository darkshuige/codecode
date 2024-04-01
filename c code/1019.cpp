#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
long long a[1000005],b[1000005];
int main()
{
	long long sum,ave,ans=0;
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		ave=sum/n;
		b[0]=0;
		for(i=1;i<n;i++)
		{
			b[i]=b[i-1]+a[i]-ave;
		}
		sort(b,b+n);
		long long x1=b[n/2];
		for(i=0;i<n;i++)
		{
			ans+=abs(x1-b[i]);
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
