#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,m,d;
		cin>>n>>m>>d;
		int a=m/n;
		if(m%n!=0)
		 a++;
		if(a>=d)
		 cout<<"Yes"<<endl;
		else
		 cout<<"No"<<endl;
	}
	return 0;
} 
