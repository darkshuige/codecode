#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 2e9
using namespace std;
const int maxn=200005;
deque<int>de;
int a[maxn];
int f[maxn];
//不能有连续的k个，也可以看成，k个连续的里面必须取走一个最小的
signed main()
{
	int n,m;
    cin>>n>>m;
    int sum=0; m++;
    for(int i=1;i<=n;i++)
     cin>>a[i],sum+=a[i];
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {
    	while(!de.empty() && f[i-1]<f[de.back()]) de.pop_back();
    	de.push_back(i-1);
    	if(de.front()<i-m) de.pop_front();
    	f[i]=a[i]+f[de.front()];
    	if(i>=n-m+1) ans=min(ans,f[i]);
	}
	cout<<sum-ans<<endl;
    return 0;
} 	