#include<bits/stdc++.h>
using namespace std;
int main()
{
	char op;
	while(cin>>op)
	{
		int count=0;
		string s;
		getchar();
		getline(cin,s);
		int pos=0;
		int dflag=0;
		while(pos!=s.size())
		{
			if(s[pos]==' ')
			{
				int flag=0;
				for(int k=0;k<pos;k++)
				{
					if(s[k]==op)
					{
						flag=1;
						dflag=1;
					}
				}
				if(flag)
				{
					string cut(s,0,pos);
					cout<<cut<<'\n';
				}
				s.erase(0,pos+1);
				pos=0;
			}
			else
			 pos++;
		}
		int flag=0;
		for(int k=0;k<pos;k++)
		{
			if(s[k]==op)
			{
				flag=1;
				dflag=1;
			}
		}
		if(flag)
		{
			string cut(s,0,pos);
			cout<<cut<<'\n';
		}
		if(dflag==0)
		{
			cout<<"No!"<<'\n';
		}
		cout<<endl;
	}
}
