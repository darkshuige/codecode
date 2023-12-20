#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<char,int>mp;
	string s;
	cin>>s;
	int i;
	int count=0;
	for(i=0;i<s.size();i++)
	{
		char a;
		a=toupper(s[i]);
		if(a=='G' || a=='P' || a=='L' || a=='T')
		{
			count++;
			mp[a]++;
		}
	}
	while(count)
	{
		if(mp['G'])
		{
			cout<<"G";
			mp['G']--;
			count--;
		}
		if(mp['P'])
		{
			cout<<"P";
			mp['P']--;
			count--;
		}
		if(mp['L'])
		{
			cout<<"L";
			mp['L']--;
			count--;
		}
		if(mp['T'])
		{
			cout<<"T";
			mp['T']--;
			count--;
		}
	}
	cout<<endl;
	return 0;
}
