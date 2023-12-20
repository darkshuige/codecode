#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int n,s;
	cin>>n>>s;
	int a=s/n;
	if(s%n==0)
	{
		for(int i=0;i<n;i++)
		{
			if(i!=0)
			 cout<<" ";
			cout<<a;
		}
		cout<<endl;
	}
	else
	{
		int op=s-(a*n);
		for(int i=0;i<n-op;i++)
		{
			if(i!=0)
			 cout<<" ";
			cout<<a;
		}
		for(int i=0;i<op;i++)
		{
			cout<<" ";
			cout<<a+1;
		}
	}
	return 0;
}
