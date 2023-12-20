#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f
using namespace std;
const int maxn=500005;
int a[maxn];
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			int op;
			cin>>op;
			a[op]++;	
		}
		if(a[k])
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	} 
	return 0;
 } 
