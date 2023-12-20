#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
		 break;
		for(int i=0;i<n+1;i++)
		{
			if(i==0 || i==n)
			{
				for(int j=0;j<m+1;j++)
				{
					if(j!=0)
					 cout<<" ";
					cout<<"*";
				}
			}
			else
			{
				for(int j=0;j<m*2+1;j++)
				{
					if(j==0 || j==m*2)
					 cout<<"*";
					else
					 cout<<" ";
				}	
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
