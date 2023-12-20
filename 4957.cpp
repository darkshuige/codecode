#include<bits/stdc++.h>
using namespace std;
int main()
{
char s[2005];
int i,t=0,flag,u;
while(cin.getline(s,2005))
{
	flag=1;
	t=0;
	for(i=0;i<strlen(s);i++)
	{
	    if(s[i]=='&')
	    {
	       t++;
	       u=i;
	    }
	    else if  (s[i]<'a' ||  s[i]>'z')
	    {
	        flag=0;
	        break;
	    }
	}
	if(u>=1000 || (strlen(s)-u-1)>=1000 ||s[0]=='&') 
	 flag=0;
	if((u!=(strlen(s)-u-1)) || t!=1 || flag==0)
	 cout<<"NO"<<endl;
	else
	{
		for(int j=0;j<u;j++)
		{
		    if(s[j]!=s[strlen(s)-j-1])
		    {
		        flag=0;
		       break;
		    }
		}
		if(flag)
		 cout<<"YES"<<endl;
		else 
		 cout<<"NO"<<endl;
		}
	}
}
