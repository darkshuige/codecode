#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=300005;
char s[maxn];
signed main() 
{
	jiasu;
    int n;
    cin>>n;
    cin>>s;
    int ans = 0;
    for (int i=0;i<n;++i) 
	{
        int l=i,r=i;
        while (l>=0 && r<n && s[l]==s[r]) 
		{
            ans++;
            l--;
            r++;
        }
        l=i,r=i+1;
        while (l>=0 && r<n && s[l]==s[r]) 
		{
            ans++;
            l--;
            r++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
