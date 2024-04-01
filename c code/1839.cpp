#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		string a1=a;
		string b1=b;
		for(int i=0;i<a1.size();i++)
		 a1[i]=tolower(a1[i]);
		for(int i=0;i<b1.size();i++)
		 b1[i]=tolower(b1[i]);
		if(a==b)
		{
			cout<<2<<endl;
		}
		else if(a1==b1)
		{
			cout<<3<<endl;
		}
		else if(a.size()==b.size())
		{
			cout<<4<<endl;
		}
		else
		{
			cout<<1<<endl;
		}
	}
	return 0;
}
