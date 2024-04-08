#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=1000055;
vector<int>v;
signed main()
{
	jiasu;
	string a,b;
	cin>>a>>b;
	reverse(a.begin(),a.end()); reverse(b.begin(),b.end());
	int pos=0;
	while(a[pos]==b[pos] && pos<a.size() && pos<b.size()) pos++;
	cout<<a.size()+b.size()-pos*2<<endl;
	return 0;
} 
