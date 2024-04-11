#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
map<int,int>mp;
const int maxn=100005;
const double PI=3.141592;
signed main()
{
	jiasu;
	double r1,r2; cin>>r1>>r2;
	cout<<fixed<<setprecision(6)<<PI*(r2*r2-r1*r1)<<endl;
	return 0;
} 	