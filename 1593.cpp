#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(m>n && m-n>1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else if(m==n+1)
		{
			for(int i=0;i<n;i++)
			{
				cout<<"10";
			}
			cout<<1<<endl;
		}
		else if(n==m)
		{
			for(int i=0;i<n;i++)
			 cout<<"01";
			cout<<endl;
		}
		else if(n>m)
		{
			cout<<0;
			for(int i=0;i<m;i++)
			{
				cout<<"10";
			}
			for(int i=0;i<n-m-1;i++)
			{
				cout<<0;
			}
			cout<<endl;
		}
	}
	return 0;
}
