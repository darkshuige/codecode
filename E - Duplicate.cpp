#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	string s;
	cin>>s;
	int flag=1;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]>'1' && s[i+1]>'1')
		 flag=0;
	}
	if(flag==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	int ans=1;
	for(int i=n-2;i>=0;i--)
	{
		ans=(ans+1+(+s[i+1]-'1')*ans)%mod;
	}
	cout<<ans-1<<endl;
	return 0;
}
