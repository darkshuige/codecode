#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	map<int,int>sb;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		sb[a]++;	
	}	
	map<int,int>::iterator it;
	for(it=sb.begin();it!=sb.end();it++)
	{
		if(it==sb.begin())
		{
			cout<<it->first<<" "<<it->second<<endl;
		}
	}
	it--;
	cout<<it->first<<" "<<it->second<<endl;
	return 0;
} 
