#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		if(s[0]=='0')
		{
			break;
		}
		int b=17;
		int yu=0;
		int i;
		for(i=0;i<s.size();i++)
		{
			yu=yu*10+(s[i]-'0');
			yu%=17;
		}
		if(yu==0)
		{
			cout<<"1"<<endl;
		}
		else
		{
			cout<<"0"<<endl;
		}
		
	}
	return 0;
}
