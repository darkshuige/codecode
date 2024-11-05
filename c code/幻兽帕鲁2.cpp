#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
__int128 f(int n, int x) 
{
    __int128 result = 0;
    for (int i = 0; i < n; ++i) 
	{
        if (x & (1 << i)) 
		{
            result |= (__int128)(1 << (n - i - 1));
        }
    }
    return result;
}
inline void print(__int128 x)
{
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
signed main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) 
	{
        int x;
        cin >> x;
        __int128 ans=f(n,x);
        print(ans);
        cout<<endl;
    }
    return 0;
}
