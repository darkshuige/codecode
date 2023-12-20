#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int count=0;
	int n=0,pos=-1;
	while(getline(cin,s))
	{
		if(s[0]=='.' && s.size()==1)
		 break;
		n++;
		for(int i=0;i<s.size();i++)
		{
			if(i+13<s.size())
			{
				string b(s,i,14);
				if(b=="chi1 huo3 guo1")
				{
					if(count==0)
					{
						pos=n;
					}
					count++;
				}	
			}	
		}	
	}
	cout<<n<<endl;
	if(count==0)
	{
		cout<<"-_-#"<<endl;
	}
	else
	{
		cout<<pos<<" "<<count<<endl;
	}
	return 0;
} 
