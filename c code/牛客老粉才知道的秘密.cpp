#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cou.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n%6==0)
		 cout<<n/6<<endl;
		else
		 cout<<n/6*2<<endl;
	}
    return 0;
}