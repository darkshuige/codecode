#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		if(s.size()==1 && s[0]=='!') break;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='a' && s[i]<='z')
			{
				cout<<(char)('z'-(s[i]-'a'));;
			}
			else if(s[i]>='A' && s[i]<='Z')
			{
				cout<<(char)('Z'-(s[i]-'A'));;
			}
			else
			 cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}
