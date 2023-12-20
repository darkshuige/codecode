#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans*=a;
        b>>=1;
        a*=a;
    }
    return ans;
}
 
int main()
{
	ll a,b;
	char s[1000];
	while(gets(s))
	{
        ll rs; char ss[1000];
        if(sscanf(s,"print %lld*%lld",&a,&b)==2) rs=a*b;
	    else if(sscanf(s,"print %lld+%lld",&a,&b)==2) rs=a+b;
	    else if(sscanf(s,"print %lld/%lld",&a,&b)==2) rs=a/b;
        else if(sscanf(s,"print %lld-%lld",&a,&b)==2) rs=a-b;
	    else if(sscanf(s,"print %lld%%%lld",&a,&b)==2) rs=a%b;
	    else if(sscanf(s,"print %lld**%lld",&a,&b)==2) rs=power(a,b);
	    else if(sscanf(s,"%*s \"%[^\"]\"*%lld",ss,&b)==2)
        {
            while(b--)
             printf("%s",ss);
            puts("");
            continue;
        }
		printf("%lld\n",rs);
	}
	return 0;
}
