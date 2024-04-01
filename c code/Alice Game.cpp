#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(flase),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int k,n;
		cin>>k>>n;
		if(n%(k+1)==0)
		 cout<<"Bob"<<endl;
		else
		 cout<<"Alice"<<endl;
	}
	return 0;
}
 
