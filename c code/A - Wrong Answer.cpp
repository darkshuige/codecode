#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
signed main()
{
	jiasu;
	int a,b;
	cin>>a>>b;
	if(a+b>0)
	 cout<<a+b-1<<endl;
	else
	 cout<<a+b+1<<endl;
	return 0;
}