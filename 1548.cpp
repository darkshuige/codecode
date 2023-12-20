#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	map<string,int>sb;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		sb[s]++;
	}
	for(int i=0;i<n-1;i++)
	{
		string s;
		cin>>s;
		sb[s]--;
	}
	map<string,int>::iterator it;
	for(it=sb.begin();it!=sb.end();it++)
	 if(it->second)
	  cout<<it->first<<endl;
	return 0;
}
