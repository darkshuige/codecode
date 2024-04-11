#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
const double PI=3.141592;
vector<int>g[27];
signed main()
{
	int n; cin>>n;
	string s; cin>>s;
	int flag=1;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]==s[0])
		{
			flag=0;
			break;
		}
	}
	if(flag) cout<<"Correct"<<endl;
	else cout<<"Wrong Answer"<<endl;
	return 0;
} 	