#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int N=200005;
int  a[N];
long long b[N];
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++) 
	{
		b[i]=b[i-1]+a[i];
	}
	while(q--)
	{
		long long sum=0;
		int  x,y;
	    scanf("%d %d",&x,&y);
	    sum=b[n-x+y]-b[n-x];
	    printf("%lld\n",sum);
	}
	return 0;
}
