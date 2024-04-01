#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	while(s[0]!='0')
	{
		int i;
		for(i=0;i<s.size();i++)
		{
			
			if(s[i]==s[i+1])
			{
				if(  s[i]=='9')
				{
					s.insert(i+1,"10");
					i=i+2;
				}
				else
				{
					s.insert(i+1,1,s[i]+1);
					i++;	
				}
				
			}
		}
		cout<<s<<endl;
		cin>>s;
	}
	return 0;
}
