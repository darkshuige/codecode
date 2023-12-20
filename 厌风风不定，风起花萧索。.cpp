#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
const int maxn=1005;
using namespace std;
int a[maxn][maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n; 
	int k=1;
	map<string,int>mp;
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(!mp[s])
		 mp[s]=k++;
		int t;
		cin>>t;
		int pos=mp[s];
		a[pos][i]+=t;
	}
	for(int i=1;i<k;i++)
	 for(int j=2;j<=n;j++)
	  a[i][j]+=a[i][j-1];
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int l,r;
		string s;
		cin>>l>>r;
		cin>>s;
		int pos=mp[s];
		cout<<a[pos][r]-a[pos][l-1]<<endl;
	}
	return 0;	
} 
