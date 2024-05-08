#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=50005;
signed main()
{
	int a,b,c; cin>>a>>b>>c;
	if(b<a && b<c)
	{
		cout<<min(a-b,c-b)<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}

