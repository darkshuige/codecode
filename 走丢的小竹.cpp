#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	int i;
	map<int,int>sb;
	for(i=0;i<n;i++)
	{
		int a;
		cin>>a;
		sb[a]++;
	}
	for(i=0;i<q;i++)
	{
		int a;
		int sum=0;
		cin>>a;
		sum=n-sb[a];
		cout<<sum<<endl;
	}
	return 0;
} 
