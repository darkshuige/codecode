#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int i;
		for(i=0;i<s.size();i++)
		{
			if(s[i]<='z' && s[i]>='a')
			{
				cout<<(char)toupper(s[i]);
			}
			else 
			 cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}
