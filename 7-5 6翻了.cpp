#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='6')
		 cout<<s[i];
		else
		{
			int k;
			int count=0;
			for(k=i;;k++)
			{
				count++;
				if(s[k]!='6')
				 break;				
			}
			count--;
			if(count<=3)
			{
				for(int j=0;j<count;j++)
				 cout<<6;
				i+=count-1;
			}
			else if(count>3 && count<=9)
			{
				cout<<9;
				i+=count-1;
			}
			else
			{
				cout<<27;
				i+=count-1;
			}
		}
	}
	cout<<endl;
	return 0;
} 
