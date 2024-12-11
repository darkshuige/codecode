#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=40005;
string init[maxn],b[maxn];
int a[maxn];
signed main()
{
	jiasu;
	int ct=1;
	for(int i=1;i<=13;i++)
	 init[ct++]="S"+to_string(i);
	for(int i=1;i<=13;i++)
	 init[ct++]="H"+to_string(i);
	for(int i=1;i<=13;i++)
	 init[ct++]="C"+to_string(i);
	for(int i=1;i<=13;i++)
	 init[ct++]="D"+to_string(i);
	init[ct++]="J1"; init[ct++]="J2";
	for(int i=1;i<=54;i++)
	 b[i]=init[i];
	int k; cin>>k;
	int n=54;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(k--)
	{
		for(int i=1;i<=n;i++)
		 b[a[i]]=init[i];
		for(int i=1;i<=54;i++)
	 	 init[i]=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=1) cout<<" ";
		cout<<init[i];
	}
	cout<<endl;
	return 0;
} 
