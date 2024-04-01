#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s))
	{
		int flag=0;
		bool m=0,n=0;
		int len=s.size();
		if(s[0]=='/' && s[1]=='/') continue;
		cout<<s[0];
		if(s[0]=='"') n=1;
		for(int i=1;i<len-1;i++)
		{
			if(s[i]=='"' && n)
			 m=1;
			else if(s[i]=='"' && !n)
			 n=1;
			if(((s[i]=='/' && s[i+1]=='/') && (n && m)) || ((s[i]=='/' && s[i+1]=='/') && (!n && !m)))
			{
				flag=1;
				break;
			}	
			else
			{
				cout<<s[i];
			}
		}
		if(flag==0)
		 cout<<s[len-1];
		cout<<endl;
	}
	return 0;
}
