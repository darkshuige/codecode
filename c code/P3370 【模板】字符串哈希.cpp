#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ull unsigned long long
using namespace std;
const int P=131;
set<ull>st;
signed main()
{
	jiasu;
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		ull sum=0;
		for(int i=0;i<s.size();i++)
		{
			sum=sum*P+(s[i]-48);
		}
		st.insert(sum);
	}
	cout<<st.size()<<endl;
	return 0;
}
