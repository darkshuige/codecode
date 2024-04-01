#include<bits/stdc++.h>
using namespace std;
char str[1000];
int mlc_pd(string s)
{
	memset(str,0,sizeof str);
	int n=0,len=s.size();
	for(int i=0;i<len;i++)
	{
		str[n++]='#';
		str[n++]=s[i];
	}
	str[n++]='#';
	int flag=1;
	int k=s.size();
	int l=k-1,r=k+1;
	while(l!=0 && r!=len-1 && flag!=0)
	{
		if(str[l]==str[r])
		{
			l--;
			r++;
		}
		else
		{
			return 0;
		}
	}
	return flag;
}
int main()
{
	string s;
	while(cin>>s)
	{
		if(mlc_pd(s))
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}	
	return 0;
}
