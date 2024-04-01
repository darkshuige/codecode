#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int len=s.length();
		for(int i=0;i<len;i++)
		{
			char a=tolower(s[i]);
			if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='y')
			{
			}
			else
			 cout<<"."<<a;
		}
		cout<<endl;
	}
	return 0;
}
