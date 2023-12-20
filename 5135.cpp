#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mod=1e9+7,t; 
    scanf("%d",&t);
    while(t--)
    {
        long long n,m; 
        scanf("%lld %lld",&n,&m);
        printf("%lld\n",(((((1+n)%mod)*(n%mod)/2)%mod)*((((1+m)%mod)*(m%mod)/2)%mod))%mod);
    }

}
