#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		long long hp,v,n,h,a,t;
		scanf("%d %d %d %d %d %d",&hp,&v,&n,&h,&a,&t);
		long long  k=(h-1)/v+1,m=t/k,sum;
    	if(k*n<=t) 
		 sum=((n*n+n)/2)*a*k;
    	else 
		 sum=(m*n*a-a*((m*m-m)/2))*k+(n-m)*a*(t%k);
		if(hp<=sum)
		 printf("Yes\n");
		else
		 printf("No\n");
	}
	return 0;
}
