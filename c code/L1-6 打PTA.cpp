#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>s;
		int flag=0;
		if(s[s.size()-1]!='?')
		{
			cout<<"enen"<<endl;
		}
		else
		{
			int j;
			for(j=0;j<s.size()-2;j++)
			{
				if(s[j]=='P' && s[j+1]=='T' && s[j+2]=='A')
				{
					flag=1;
				}
			}
			if(flag)
			 cout<<"Yes!"<<endl;
			else
			 cout<<"No."<<endl;
		}
	}
	return 0;
}
