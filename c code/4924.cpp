#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s))
	{
		int i=0;
		for(i;i<s.size();i++)
		{
			if(i==0)
			{
				cout<<(char)toupper(s[i]);
			}
			else
			{
				if(s[i]!=' ' && s[i-1]==' ')
				{
					cout<<(char)toupper(s[i]);
				}
				else
				{
					cout<<s[i];
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
