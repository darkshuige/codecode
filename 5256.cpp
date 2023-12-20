#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<int,int>sb;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		sb[a]++;
		if(i!=0) cout<<" ";
		cout<<sb[a];
	}
	cout<<endl;
	return 0;
} 
