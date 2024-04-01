#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int n;
	char a;
	cin>>n>>a;
	getchar();
	getline(cin,s);
	if(s.size()>=n)
	{
		int i;
		for(i=s.size()-n;i<s.size();i++)
		{
			cout<<s[i];
		}
		cout<<endl;
	}
	else
	{
		int i;
		for(i=n-s.size();i;i--)
		 cout<<a;
		cout<<s<<endl;
	}
	return 0;
}
