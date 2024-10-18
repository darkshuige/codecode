#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
int f(int n, int x) 
{
    int result = 0;
    for (int i = 0; i < n; ++i) 
	{
        if (x & ((int)1 << i))
		{
            result +=((int)(1) << (n - i - 1));
        }
    }
    return result;
}
signed main() 
{
    jiasu;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) 
	{
        int x;
        cin >> x;
        cout<<f(n,x)<<endl;
    }
    return 0;
}
