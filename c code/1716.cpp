#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		map<int,int>mp;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			mp[a]++;
		}
		int count=0;
		while(1)
		{
			count+=mp.size()-1;
			map<int,int>::iterator it;
			for(it=mp.begin();it!=mp.end();)
			{
				it->second--;
				if(it->second==0)
				{
					int op=it->first;
					it++;
					mp.erase(op);
				}
				else
				{
					it++;
				}
				if(mp.size()==0 || mp.size()==1)
				{
					goto ee;
				}
			}	
		}
		ee:
		cout<<count<<endl;
	}
	return 0;
} 
