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
	string ans;
	char s; string ss;
	int now=0;
	getline(cin,ss);
	for(int i=0;i<ss.size();i++)
	{
		s=ss[i];
		if(s==' ' || s=='.' || s=='?' || s==',' || s=='!')
		{
			if(now!=0)
			{
				ans+=to_string(now%10);
				now=0;	
			}
		}
		else now++;
	}
	if(now)
	 ans+=to_string(now%10);
	cout<<ans<<endl;
	return 0;
} 	