#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int flag=1;
		int len=s.size();
		if(s[0]==s[len/3] || s[0]==s[(len/3)*2] || s[len/3]==s[(len/3)*2])
		 flag=0;
		if(len%3!=0 || len<3)
		 flag=0;
		for(int i=1;i<len/3;i++)
		{
			if(s[i]!=s[i-1])
			 flag=0;
		}	
		for(int i=len/3+1;i<(len/3)*2;i++)
		{
			if(s[i]!=s[i-1])
			 flag=0;
		}
		for(int i=(len/3)*2+1;i<len;i++)
		{
			if(s[i]!=s[i-1])
			 flag=0;
		}
		if(flag)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
}
