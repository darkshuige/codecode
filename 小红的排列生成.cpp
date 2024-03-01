#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int a[maxn];
signed main()
{
    jiasu;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
     cin>>a[i];
    int sum=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
     sum+=abs(i-a[i]);
    cout<<sum<<endl;
    return 0;
}
