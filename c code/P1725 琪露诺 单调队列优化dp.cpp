#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
int a[maxn];
int f[maxn];
deque<int>de;
int n,l,r;
signed main()
{
    cin>>n>>l>>r;
    memset(f,-inf,sizeof f); f[0]=0;
    for(int i=0;i<=n;i++) cin>>a[i];
    int ans=LLONG_MIN;
    for(int i=l;i<=n;i++)
    {
    	while(!de.empty() && f[i-l]>f[de.back()]) de.pop_back();
    	de.push_back(i-l);
    	if(de.front()<i-r) de.pop_front();
    	f[i]=a[i]+f[de.front()];
    	if(i>=n-r+1) ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
    return 0;
} 	