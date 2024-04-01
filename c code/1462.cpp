#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		map<char,int>sb;
		int flag=1;
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++)
		 sb[s[i]]++;
		string b;
		cin>>b;
		for(int i=0;i<b.size();i++)
		{
			if(sb[b[i]])
			{
				sb[b[i]]--;
			}
			else
			{
				flag=0;
			}
		}
		if(flag)
		 cout<<"Yes"<<endl;
		else
		 cout<<"No"<<endl;
	}
	return 0;
}
