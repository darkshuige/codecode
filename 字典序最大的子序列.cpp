#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
int f(string s,int pos)
{
	int p=pos;
	for(int i=pos;i<s.size();i++)
	{
		if(s[i]>s[p])
		 p=i;
	}
	return p;
}
signed main()
{
	jiasu;
	string s;
	cin>>s;
	int pos=0;
	string ans="";
	while(pos<s.size())
	{
		pos=f(s,pos);
		cout<<s[pos];
		pos++; 
	}
	return 0;
} 
