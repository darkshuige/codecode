#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
signed main()
{
    int n;
    cin>>n;
    int flag=0;
    int mal=0;
    int ma=2;
    int l=2;
    for(int i=2;i<=sqrt(n);i++)
    {
        int r=i,now=i;
        while(now<=n)
        {
            if(n%now==0)
            {
                flag=1;
                if(r-i+1>mal)
                {
                    mal=r-i+1;
                    ma=r;
                    l=i;
                }
            }
            r++;
            now*=r;
        }
    }
    if(flag)
    {
        cout<<ma-l+1<<endl;
        for(int i=l;i<=ma;i++)
        {
            if(i!=l) cout<<"*";
            cout<<i;
        }
    }
    else
    {
        cout<<1<<endl;
        cout<<n<<endl;
    }
    return 0;
}