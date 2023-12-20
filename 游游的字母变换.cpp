#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(flase),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
string s;
signed main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='Z' && s[i]>='A')
		{
			if(s[i]=='Z')
			 cout<<'A';
			else
			 cout<<(char)(s[i]+1);
		}
		else if(s[i]<='z' && s[i]>='a')
		{
			if(s[i]=='a')
			 cout<<'z';
			else
			 cout<<(char)(s[i]-1);
		}
		else
		{
			cout<<s[i];
		}
	}
	cout<<endl;
	return 0;
}
 
