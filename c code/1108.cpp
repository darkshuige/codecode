#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		
		for(i=0;i<n;i++)
		{
			string s;
			int pos;
			int flag1=0,flag2=0,flag3=0;
			cin>>s;
			int count=0;
			for(int j=0;j<s.size();j++)
			{
				if(s[j]>='A' && s[j]<='Z')
				 count++;
			}
			if(count==3)
			 flag3=1;
			pos=s.find("Li");
			if(pos!=string::npos)
			 flag1=1;
			pos=s.find("Ting");
			if(pos!=string::npos)
			 flag2=1;
			if(flag1 && flag2 && flag3)
			 cout<<s<<endl;
		}	
	}
	return 0;
} 
