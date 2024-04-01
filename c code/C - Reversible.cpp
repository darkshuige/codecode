#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int n;
	cin>>n;
	set<string>st;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		string cp=s;
		reverse(cp.begin(),cp.end());
		if(st.count(cp)==0 && st.count(s)==0)
		 st.insert(s);
	}
	cout<<st.size()<<endl;
	return 0;
} 
