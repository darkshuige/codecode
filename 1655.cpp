#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	string p;
	while(cin>>s>>p)
	{
		while(s.find(p)!=-1)
		{
			s.erase(s.find(p),p.size());
		}
		cout<<s<<endl;
	}
	return 0;
}
