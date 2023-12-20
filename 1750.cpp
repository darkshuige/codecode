#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		getchar();
		for(int i=0;i<s.length();i++)
		 s[i]=tolower(s[i]);
		string str;
		getline(cin,str);
		for(int i=0;i<str.length();i++)
		 str[i]=tolower(str[i]);
		s=' '+s+' ';
		str=' '+str+' ';
		int ans=str.find(s);
		int flag=0,cnt=0;
		int po=-1;
		while(ans!=string::npos)
		{
			if(ans>=0)
			{
				if(flag==0)
				{
					po=ans;
					 flag=1;
				}
				cnt++;
			}
			ans=str.find(s,ans+1);
		}
		if(cnt)
		cout<<cnt<<" "<<po<<endl;
		else
		cout<<po<<endl;
	}
}
