#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
signed main()
{
	int a,b; cin>>a>>b;
	if(a==1 || a==0)
	{
		if(b==1)
		{
			cout<<"-"<<endl;
			if(a==1)
			{
				cout<<"move"<<endl;
			}
			else if(a==0)
			{
				cout<<"stop"<<endl;
			}
		}
		 
		else if(b==0)
		{
			if(a==1)
			{
				cout<<"dudu"<<endl;
				cout<<"move"<<endl;
			}
			else if(a==0)
			{
				cout<<"biii"<<endl;
				cout<<"stop"<<endl;
			}
		}
	}
	else if(a==2)
	{
		cout<<"-"<<endl;
		cout<<"stop"<<endl;
	}
	return 0;
}