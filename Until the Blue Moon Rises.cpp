#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	if(n==1)
	{
		int op;
		cin>>op;
		int flag=0;
		for(int i=2;i<=sqrt(op);i++)
		{
			if(op%i==0)
			{
				cout<<"No"<<endl;
				flag=1;
				break;	
			}
		}
		if(flag==0)
		 cout<<"Yes"<<endl;
	}
	else if(n==2)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int op;
			cin>>op;
			sum+=op;
		}
		if(sum>2 && sum%2==0)
		 cout<<"Yes"<<endl;
		else 
		 cout<<"No"<<endl;	
	}
	else
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int op;
			cin>>op;
			sum+=op;
		}
		if(sum>=n*2)
		 cout<<"Yes"<<endl;
		else 
		 cout<<"No"<<endl;
	}
	return 0;
}
