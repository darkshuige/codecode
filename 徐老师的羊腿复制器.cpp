#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int sum1=0,sum2=0;
    	while(n)
    	{
    		if(n%2==1)
    		 sum1++;
    		sum2++;
    		n/=2;
		}
		cout<<sum1*2+sum2-2<<endl;
		cout<<sum1<<endl<<sum2<<endl;
	}
    return 0;
}
