#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int mod=1000000007;
const int maxn=10000005;
int a[maxn];
void init()
{
	a[0]=0;
	a[1]=1;
	a[2]=2;
	a[3]=3;
	for(int i=4;i<=maxn;i++)
	 a[i]=(a[i-1]+a[i-3])%mod;
}
signed main()
{
	jiasu;
	init();
	int x;
	cin>>x;
	cout<<a[x]<<endl;
	return 0;	
} 
