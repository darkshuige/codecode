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
		string a[15];
		for(int j=0;j<n;j++)
		 cin>>a[j];
		sort(a,a+n);
		for(int j=0;j<n;j++)
		 cout<<a[j]<<endl;
	}
	return 0;
} 
