#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		map<int,int>sb;
		int i;
		for(i=0;i<n;i++)
		{
			int a;
			cin>>a;
			sb[a]++;
		}
		map<int,int>::iterator it;
		for(it=sb.begin();it!=sb.end();it++)
		{
			if(it->second==2)
			{
				cout<<it->first<<endl;
			}
		}
	}
	return 0;
}
