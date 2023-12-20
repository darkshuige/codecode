#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
    	long long n=0,m;
    	string s;
    	cin>>s>>m;
    	for(int j=0;j<s.size();j++)
    	{
    		n=n*10+(s[j]-48);
            if(n >= m) 
			 break;
		}
		long long sum=1,num=1;
		if(n>=m || s.size()>7)
		 n=m-1;
		for(int j=1;j<=n;j++)
		{
			num=num*j%m;
			sum=(sum+num)%m;
            if(num==0)
			 break;
		}
		printf("%lld\n",sum%m);
	}
	return 0;
}
