#include<bits/stdc++.h>
//#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int gcd(int a,int b)
{
    if(a<b)
     swap(a,b);
    int t=a%b;
    while(t)
    {
    	a=b;
    	b=t;
    	t=a%b;
	}
	return b;
}
signed main()
{
	jiasu;
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int a,k,c,n,b,cnt=0;
		cin>>k>>c>>n;
		if(c<=n)
		{
			cout<<0<<endl;
			continue;
		}
		for(int j=ceil(c/(c-k*n*1.0));j<=c/n;j++)
		{
			if(c%j==0)
			{
				b=c/j;
				if((c-b)%k==0)
				 a=(c-b)/k;	
				else
				 continue;
				if(a>0 && b>0)
				 if(gcd(a,b)>=n)
				  cnt++;	
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
