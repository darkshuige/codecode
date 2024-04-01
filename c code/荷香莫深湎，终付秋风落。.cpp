#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
signed main()
{
	jiasu;
	string s;
	int cnt=0;
	while(cin>>s)
	{
		for(int i=0;i<s.length()-1;i++)
		{
			if(s[i]==':' && s[i+1]=='w')
			 cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;	
} 
