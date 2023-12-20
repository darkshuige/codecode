#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		{
			cout<<1<<endl;
			continue;
		}
		cout<<5;
		for(int i=0;i<n-1;i++)
		 cout<<0;
		cout<<5;
		for(int i=0;i<n-1;i++)
		 cout<<0;
		cout<<endl;
	}
}
