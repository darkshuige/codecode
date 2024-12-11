#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
int b[maxn];
multiset<int>st,st2;
signed main()
{
	string s; cin>>s;
	int ct=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		b[ct]=s[i]-'0';
		st.insert(b[ct]);
		b[ct++]*=2;
	}
	for(int i=0;i<ct;i++)
	{
		if(b[i]>=10)
		{
			b[i+1]+=b[i]/10;
			b[i]%=10;
		}
	}
	if(b[ct]>0) ct++;
	for(int i=0;i<ct;i++)
	 st2.insert(b[i]);
	if(st==st2)
	 cout<<"Yes"<<endl;
	else
	 cout<<"No"<<endl;
	for(int i=ct-1;i>=0;i--)
	 cout<<b[i];
	cout<<endl;
	return 0;
} 