#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int n;
	cin>>n;
	int sum1=0;
	for(int i=0;i<n;i++)
	{
		char op;
		cin>>op;
		if(op=='(')
		{
			sum1=1;
			cout<<"(";
		}
		else if(op==')' && sum1==1)
		{
			sum1=0;
			cout<<")";
		}
		else if(op==',' && sum1==1)
		 cout<<".";
		else if(op==',' && sum1==0)
		 cout<<",";
		else 
		 cout<<op;
	}
	cout<<endl;
	return 0;
}
