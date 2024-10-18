#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, m;
    cin >> n >> m;
    ll tt = (1 << n);
    while(m --) {
        ll x;
        cin >> x;
        ll ans = 0;
        for(int i = 0; i < n; i ++) {
            ll b = (x & 1);
            x >>= 1;
            ans += b * (1LL << (n - i - 1));
        }
        cout << ans << '\n';
    }
}