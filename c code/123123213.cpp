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
	a[0]=0; 
//	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		cout<<a[op]<<endl;
	}
	return 0;
 } 
