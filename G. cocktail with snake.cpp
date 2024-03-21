#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int x=k/n;
		int y=k%n;
		if((x & 1)) y=n-1-y;
		cout<<abs(0-x)+abs(0-y)<<endl;
	}
	return 0;
}
//10
//3 3 1
//3 3 2
//3 3 3
//3 3 4
//3 3 5
//3 3 6
//3 3 7
//3 3 8
//3 3 9
//3 3 10