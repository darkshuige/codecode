#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=100005;
signed main()
{
	jiasu;
	double r1,r2,s1,s2;
	cin>>r1>>r2>>s1>>s2;
	r1--;r2--;
	if(r1/s1<r2/s2) cout<<"TAOYUAN\n";
	else if(r1/s1>r2/s2) cout<<"JAKARTA\n";
	else cout<<"SAME\n";
	return 0;
} 
