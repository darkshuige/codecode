#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		map<long long,int>mp;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			mp[a]++;
		}
		map<long long,int>::iterator it;
		for(it=mp.begin();it!=mp.end();it++)
		{
			cout<<it->first<<" "<<it->second<<endl;
		}
	}
	return 0;
}
