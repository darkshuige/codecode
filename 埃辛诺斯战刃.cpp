#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		 cout<<"*";
		cout<<endl;
	}
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n-1;i++)
		{
			cout<<" ";
		}	
		cout<<"*"<<endl;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<i;j++)
		 cout<<"*";
		cout<<endl;
	}
    return 0;
}
