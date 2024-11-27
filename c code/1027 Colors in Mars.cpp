#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10005;
const int st=8*3600;
const int ed=21*3600;
map<int,char>mp;
signed main()
{
	for(int i=0;i<=9;i++)
	 mp[i]=(i+'0');
	mp[10]='A';
	mp[11]='B';
	mp[12]='C';
	int a,b,c;
	cin>>a>>b>>c;
	cout<<"#";
	string s;
	string k;
	while(a)
	{
		k+=mp[a%13];
		a/=13;
	}
	reverse(k.begin(),k.end());
	while(k.size()<2)
	 k="0"+k;
	s+=k;
	k="";
	while(b)
	{
		k+=mp[b%13];
		b/=13;
	}
	reverse(k.begin(),k.end());
	while(k.size()<2)
	 k="0"+k;
	s+=k;
	k="";
	while(c)
	{
		k+=mp[c%13];
		c/=13;
	}
	reverse(k.begin(),k.end());
	while(k.size()<2)
	 k="0"+k;
	s+=k;
	cout<<s<<endl;
	return 0;
} 