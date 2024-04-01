#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		map<char,int>sb;
		string s;
		cin>>s;
		int count=0;
		for(int j=0;j<s.size();j++)
		{
			sb[s[j]]++;
			if(sb[s[j]]==1)
			 count+=2;
			else
			 count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
