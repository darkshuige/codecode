#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			int x,y;
			cin>>x>>y;
		}
		int ans=1;
		for(int j=2;j<=n;j++)
		 ans^=j;
		cout<<ans<<endl;
	}
	return 0;
} 
