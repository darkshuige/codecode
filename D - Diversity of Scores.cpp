#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=400005;
int a[maxn];
map<int,int>mp;
signed main()
{
	jiasu;
	int n,t;
	cin>>n>>t;
	for(int i=0;i<n;i++)
	 mp[0]++;
	for(int i=0;i<t;i++)
	{
		int aa,bb;
		cin>>aa>>bb;
		mp[a[aa]]--;
		if(mp[a[aa]]==0)
		 mp.erase(a[aa]);
		a[aa]+=bb;
		mp[a[aa]]++;
		cout<<mp.size()<<endl;
	}
	return 0;
}