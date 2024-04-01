#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[105][105];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int j=0;j<n;j++)
		{
			for(int i=0;i<n;i++)
			{
				if(i!=0)
				 cout<<" ";
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
} 
