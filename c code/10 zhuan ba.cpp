#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	stack<int>st;
	while(n)
	{
		st.push(n%8);
		n/=8;
	}
	while(!st.empty())
	{
		cout<<st.top();
		st.pop();
	}
	return 0;
} 
