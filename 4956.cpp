#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s))
	{
		int da=0,xiao=0,shuzi=0,space=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='a' && s[i]<='z')
			 xiao++;
			else if(s[i]>='A' && s[i]<='Z')
			 da++;
			else if(s[i]==' ')
			 space++;
			else if(s[i]>='0' && s[i]<='9')
			 shuzi++;
		}
		printf("%d %d %d %d\n",da,xiao,shuzi,space);
	}
	return 0;
} 
