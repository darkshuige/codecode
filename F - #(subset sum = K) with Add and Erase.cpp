#include <bits/stdc++.h>
#define int long long
#define M 10005
#define mod 998244353
using namespace std;
int Q, K, dp[M], x;
char ch;
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> Q >> K;
    dp[0] = 1;
    for(int i = 1; i <= Q; ++ i) 
	{
        cin >> ch >> x;
        if(ch == '+') 
		{
	        for(int i = 5000; i >= x; -- i)
	         if(dp[i - x])
	          dp[i] = (dp[i] + dp[i - x]) % mod;
        }
        else
         for(int i = x; i <= 5000; ++ i)
          if(dp[i - x])
           dp[i] = (dp[i] - dp[i - x] + mod) % mod;
        cout << dp[K] << '\n';
    }
}
