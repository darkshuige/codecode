#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int a[maxn];
signed main() 
{
    jiasu;
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
     cin>>a[i];
    sort(a+1,a+n+1);
    int pos=0;
    while(a[pos]<=x && pos<=n) pos++;
    pos--;
    cout<<pos<<" "<<x-a[pos]<<endl;
    return 0;
}
