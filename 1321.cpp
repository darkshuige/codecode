#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int,int>sb;
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		int a;
		cin>>a;
		sb[a]++;
	}
	int maxn=INT_MIN;
	map<int,int>::iterator it;
	for(it=sb.begin();it!=sb.end();it++)
	{
		if(it->second>maxn)
		{
			maxn=it->second;
		}
	}
	for(it=sb.begin();it!=sb.end();it++)
	{
		if(it->second==maxn)
		{
			cout<<it->first<<endl<<it->second<<endl;
		}
	}
	return 0;
}
