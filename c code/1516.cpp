#include<bits/stdc++.h>
using namespace std;
int f(char a)
{
	if(a>='A' && a<='Z')
	 return 1;
	else 
	 return 0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int len=s.size();
		int flag=0;
		if(len%2==0)
		{
			for(int j=2;j<=len-2;j+=2)
			{
				string a(s,0,j);
				string b(s,j,(len-j)/2);
				string c(s,j+(len-j)/2,(len-j)/2);
				if(a!=b && a!=c && b==c && f(b[0]) && f(c[0]))
				 flag=1;
			}
		}
		else if(len%2!=0)
		{
			for(int j=1;j<=len-2;j+=2)
			{
				string a(s,0,j);
				string b(s,j,(len-j)/2);
				string c(s,j+(len-j)/2,(len-j)/2);
				if(a!=b && a!=c && b==c && f(b[0]) && f(c[0]))
				 flag=1;
			}
		}
		if(flag)
		 cout<<"Yes"<<endl;
		else
		 cout<<"No"<<endl;
	}
	return 0;
} 
