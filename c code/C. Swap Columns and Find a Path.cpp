#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=5005;
map<char,int>mp;
int a[maxn],b[maxn];
int vis1[maxn],vis2[maxn];
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		memset(vis1,0,sizeof vis1); memset(vis2,0,sizeof vis2);
		int n; cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		int pos=0;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=max(a[i],b[i]);
			if(a[i]>b[i]) vis1[i]=1;
			else vis2[i]=1;
		}
		int ma=INT_MIN;
		for(int i=0;i<n;i++)
		{
			if(vis1[i]) continue;
			if(a[i]>ma) ma=a[i];
		}
		for(int i=0;i<n;i++)
		{
			if(vis2[i]) continue;
			if(b[i]>ma) ma=b[i];
		}
		cout<<sum+ma<<endl;
	}
	return 0;
} 
