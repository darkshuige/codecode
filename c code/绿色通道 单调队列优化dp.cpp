#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 2e9
using namespace std;
const int maxn=200005;
int a[maxn];
int f[maxn];
deque<int>de;
int n,t;
int check(int k)
{
	k++;
	de.clear(); memset(f,0,sizeof f);
	//计算最长长度为k的情况下要的最少量 
	int ans=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		while(!de.empty() && f[i-1]<f[de.back()]) de.pop_back();
		de.push_back(i-1);
		if(de.front()<i-k) de.pop_front();
		f[i]=a[i]+f[de.front()];
		if(i>=n-k+1) ans=min(ans,f[i]);
	}
	return ans<=t;
}
signed main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=0,r=n,ans=0;
    while(l<=r)
    {
    	int mid=l+r>>1;
    	if(check(mid))
    	{
    		ans=mid;
    		r=mid-1;
		}
		else
		 l=mid+1;
	}
	cout<<ans<<endl;
    return 0;
} 	