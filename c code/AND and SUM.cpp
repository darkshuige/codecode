#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,s;
		cin>>a>>s;
		if(s>=2*a && ((s-2*a)&a)==0)
		 cout<<"Yes"<<endl;
		else 
		 cout<<"No"<<endl;
	}
	return 0;
}
