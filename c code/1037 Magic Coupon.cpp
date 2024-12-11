#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
string a[maxn];
int cmp(string a,string b)
{
	return a+b<b+a;
}
signed main()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	sort(a,a+n,cmp);
	string ans;
	for(int i=0;i<n;i++) ans+=a[i];
	while(ans[0]=='0')
	 ans.erase(0,1);
	if(ans.size()!=0)
	 cout<<ans<<endl;
	else
	 cout<<"0"<<endl;
	return 0;
} 
