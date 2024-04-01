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
			 cin>>a[i][j];
		}
		int flag=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]!=a[j][i])
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
		 cout<<"Yes!"<<endl;
		else
		 cout<<"No!"<<endl;
	}
	return 0;
}
