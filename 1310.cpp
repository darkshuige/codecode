#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
    	map<char,int>sb;
    	for(int i=0;i<4;i++)
    	{
			string s;
			cin>>s;
			for(int k=0;k<s.size();k++)
			{
				sb[s[k]]++;		
			}    			
		}
		int flag=1;
		map<char,int>::iterator it;
		for(it=sb.begin();it!=sb.end();it++)
		{
			if(it->first!='.' && it->second>2*n)
			{
				flag=0;
			}
		}
		if(flag)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
}
