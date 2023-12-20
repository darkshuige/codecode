#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,s1;
	while(getline(cin,s))
	{
		s1=s;
		for(int i=0;i<s.size();i++)
		 s[i]=tolower(s[i]);
		for(int i=0;i<s.size();i++)
		{
			string cut(s,i,9);
			if(cut=="marshtomp")
			{
				cout<<"fjxmlhx";
				i+=8;
			}
			else
			 cout<<s1[i];
		}
		cout<<endl;
	}
	return 0;
}
