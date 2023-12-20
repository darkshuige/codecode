#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int pos1=s.find('H'),pos2=s.find('Q'),pos3=s.find('9');
		if(pos1!=string::npos || pos2!=string::npos || pos3!=string::npos)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
} 
