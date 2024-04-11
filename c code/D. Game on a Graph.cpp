#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int n,m,k;
		string s; 
		cin>>k>>s;
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			int a,b;
			cin>>a>>b;
		}
		int kk=n-2;
		int kkk=m-kk;
		if(s[kkk-1]=='1')
		 cout<<2<<endl;
		else
		 cout<<1<<endl;
	}
	return 0;
} 	