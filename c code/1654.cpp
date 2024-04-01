#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,m,i,j;
	string s;
	while(cin>>s)
	{
		long long sum=1;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='A'||s[i]=='a')
			{
				sum*=6;
			}
			else if(s[i]=='B'||s[i]=='b')
			{
				sum*=9;
			}
			else if(s[i]=='C'||s[i]=='c')
			{
				sum*=0;
			}
			else if(s[i]=='D'||s[i]=='d')
			{
				sum*=5;
			}
			else if(s[i]=='E'||s[i]=='e')
			{
				sum*=8;
			}
			else if(s[i]=='F'||s[i]=='f')
			{
				sum*=1;
			}
			else if(s[i]=='G'||s[i]=='g')
			{
				sum*=9;
			}
			else if(s[i]=='H'||s[i]=='h')
			{
				sum*=4;
			}
			else if(s[i]=='I'||s[i]=='i')
			{
				sum*=6;
			}
			else if(s[i]=='J'||s[i]=='j')
			{
				sum*=3;
			}
			else if(s[i]=='K'||s[i]=='k')
			{
				sum*=2;
			}
			else if(s[i]=='L'||s[i]=='l')
			{
				sum*=34;
			}
			else if(s[i]=='M'||s[i]=='m')
			{
				sum*=67;
			}
			else if(s[i]=='N'||s[i]=='n')
			{
				sum*=67;
			}
			else if(s[i]=='O'||s[i]=='o')
			{
				sum*=78967;
			}
			else if(s[i]=='P'||s[i]=='p')
			{
				sum*=345;
			}
			else if(s[i]=='Q'||s[i]=='q')
			{
				sum*=454;
			}
			else if(s[i]=='R'||s[i]=='r')
			{
				sum*=434;
			}
			else if(s[i]=='S'||s[i]=='s')
			{
				sum*=345;
			}
			else if(s[i]=='T'||s[i]=='t')
			{
				sum*=12;
			}
			else if(s[i]=='U'||s[i]=='u')
			{
				sum*=978;
			}
			else if(s[i]=='V'||s[i]=='v')
			{
				sum*=563;
			}
			else if(s[i]=='W'||s[i]=='w')
			{
				sum*=34;
			}
			else if(s[i]=='X'||s[i]=='x')
			{
				sum*=34;
			}
			else if(s[i]=='Y'||s[i]=='y')
			{
				sum*=5885;
			}
			else if(s[i]=='Z'||s[i]=='z')
			{
				sum*=45;
			}
			sum=sum%751492854;
		}
		cout<<sum<<endl;
	}
} 
