#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<string,int>mp;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int j;
		string s;
		cin>>j;
		if(j==1)
		{
			cin>>s;
			continue;
		}
		for(int k=0;k<j;k++)
		{
			cin>>s;
			mp[s]++;
		}
	}
	int count=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		if(mp[s]==0)
		{
			mp[s]++;
			if(count!=0)
			 cout<<" ";
			cout<<s;
			count++;
		}
	}
	if(count==0)
	 cout<<"No one is handsome";
	cout<<endl;
	return 0;
}
