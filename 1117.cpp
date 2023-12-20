#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		map<int,int>mp;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x==0)
			{
				sum+=mp.size();
				mp.clear();
			}
			else
			 mp[x]++;
		}
		sum+=mp.size();
		cout<<sum<<endl;
	}
	return 0;
}
