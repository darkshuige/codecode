#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,t;
    while(scanf("%lld %lld %lld",&n,&k,&t)!=EOF)
    {
    	long long sum=0,x=1,y=1; 
        for(int i=1;i<=t;i++)
        { 
            sum+=x; 
            x=(x+(2*y+n-1)*n/2)%k; 
            y+=n; 
        }
		printf("%lld\n",sum);
	}
    return 0;
}
