#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000050;
const int mod=998244353;
signed main()
{
	jiasu;
	string s;
	cin>>s;
	int flag=1;
	for(int i=1;i<s.size();i+=2)
	{
		if(s[i]!='0')
		 flag=0;
	} 
	if(flag)
	 cout<<"Yes"<<endl;
	else
	 cout<<"No"<<endl;
	return 0;
}
