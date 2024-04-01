#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int MAXN = 1000005;
const int MAXK = 1000005;
int w[MAXN], v[MAXN];
int dp[MAXK + 1];
signed main() 
{
	jiasu;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) 
     cin >> w[i] >> v[i];
    int q;
    cin >> q;
    while(q--) 
	{
        int k;
        cin >> k;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) 
         for(int j = k; j >= w[i]; j--) 
          dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        cout << dp[k] << endl;
    }
    return 0;
}