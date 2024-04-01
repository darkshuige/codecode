#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int pos=1;
		while(pos<s.size() && s[pos]==s[pos-1]) pos++;
		if(pos==s.size())
		{
			cout<<s.size()-1<<endl;
		}
		else
		{
			cout<<s.size()+s.size()-pos<<endl;
		}
	}
	return 0;
}
