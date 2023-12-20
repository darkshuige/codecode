#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int n;
	string s;
	cin>>n>>s;
	int pos=s.find("ABC");
	if(pos==string::npos)
	 cout<<-1<<endl;
	else
	 cout<<pos+1<<endl;
	return 0;
}
