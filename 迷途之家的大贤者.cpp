#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
signed main() 
{
    jiasu;
    int n;
    string s;
    cin>>n>>s;
    if(s[0]==s[s.size()-1])
     cout<<s[0]<<endl;
    else
     cout<<max(s[0],s[s.size()-1])<<endl;
    return 0;
}
