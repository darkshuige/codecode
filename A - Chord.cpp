#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
signed main()
{
	jiasu;
	string s;
	cin>>s;
	if(s=="ACE" || s=="BDF" || s=="CEG" || s=="DFA" || s=="EGB" || s=="FAC" || s=="GBD")
	 cout<<"Yes"<<endl;
	else
	 cout<<"No"<<endl;
	return 0;
} 
