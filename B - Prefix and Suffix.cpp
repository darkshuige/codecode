#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int n,m;
	string a,b;
	cin>>n>>m>>a>>b;
	int flag1=0,flag2=0;
	string cp=b.substr(0,n);
	if(cp==a) flag1=1;
	cp=b.substr(m-n);
	if(cp==a) flag2=1;
	if(flag1 && flag2)
	 cout<<0<<endl;
	else if(flag1 && !flag2)
	 cout<<1<<endl;
	else if(!flag1 && flag2)
	 cout<<2<<endl;
	else
	 cout<<3<<endl;
	return 0;
}
