#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2005;
int n,k;
vector<pair<string,string> >ans;
signed main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string a,b; cin>>a>>b;
		int flag=0;
		for(int i=0;i<b.size();i++)
		{
			if(b[i]=='1')
			{
				b[i]='@'; flag=1;
			}
			else if(b[i]=='0')
			{
				b[i]='%'; flag=1;
			}
			else if(b[i]=='l')
			{
				b[i]='L'; flag=1;
			}
			else if(b[i]=='O')
			{
				b[i]='o'; flag=1;
			}
		}
		if(flag)
		 ans.push_back({a,b});
	}
	if(ans.size()==0)
	{
		if(n!=1 && n!=0)
		 cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
		else
		 cout<<"There is "<<n<<" account and no account is modified"<<endl;
	}
	 
	else
	{
		cout<<ans.size()<<endl;
		for(auto k:ans)
		 cout<<k.first<<" "<<k.second<<endl;
	}
	return 0;
} 
