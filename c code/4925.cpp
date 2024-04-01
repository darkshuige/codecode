#include<bits/stdc++.h>
using namespace std;
int main()
{
	string cut1,cut2;
	cin>>cut1;
	cut2=cut1;
	for(int i=0;i<cut2.size();i++)
	 cut2[i]=tolower(cut2[i]);
	string s;
	getchar();
	while(getline(cin,s))
	{
		string s2=s;
		int i=0;
		int l2=cut2.size();
		int l1=s.size();
		int pos;
		for(int i=0;i<l1;i++)
		 s2[i]=tolower(s2[i]);
		pos=s2.find(cut2);
		while(pos!=string::npos)
		{
			s.erase(pos,l2);
			s2.erase(pos,l2);
			pos=s2.find(cut2);
		}
		pos=s.find(' ');
		while(pos!=string::npos)
		{
			s.erase(pos,1);
			pos=s.find(' ');
		}
		cout<<s<<"\n";
	}
	return 0;
}
