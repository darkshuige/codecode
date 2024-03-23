#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
const int maxn=100005;
int a[maxn];//怪物原来生命
int b[maxn];//僧名+盾
int s[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++)
	 b[i]+=a[i]+ceil((double)a[i-1]/2);
	for(int i=2;i<=n;i++)
	 s[i]=s[i-1]+floor((double)a[i-1]/2);
	int ma=a[1];
	for(int i=2;i<=n;i++)
	 ma=max(ma,b[i]-s[i]);
	cout<<ma+1<<endl;
    return 0;
} 
