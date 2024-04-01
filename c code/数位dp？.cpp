#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
signed main()
{
	jiasu;
	string s;
	cin>>s;
	int cnt,i;
	for(cnt=0,i=s.size()-1;i>=0;i--,cnt++)
	{
		if((s[i]-'0')%2==0)
		 break;
	}
	cout<<cnt<<endl;
	return 0;
}
