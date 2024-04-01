#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
map<string,pair<int,int>>lo;
map<pair<int,int>,pair<int,int>>f;
map<pair<int,int>,string>fa;
map<string,int>cnt;
pair<int,int>fi(pair<int,int>x)
{
    if(f[x]==x)return x;
    return f[x]=fi(f[x]);
}
signed main()
{
    jiasu;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
        string s;
        int x,y;
        cin>>s>>x>>y;
        lo[s]={x,y};
        auto l=fa.find({x,y});
        if(l==fa.end())
        {
            fa[{x,y}]=s;
            cnt[s]=1;
            f[{x,y}]={x,y};
        }
        else
        {
            string tmp=fa[{x,y}];
            if(tmp<s)fa[{x,y}]=s,lo.erase(tmp),cnt[s]=1;
            else lo.erase(s);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        string s,op;
        cin>>s>>op;
        if(lo.find(s)==lo.end())
        {
            cout<<"unexisted empire.\n";
            continue;
        }
        int x=lo[s].first,y=lo[s].second;
        if(op=="W")x--;
        else if(op=="S")x++;
        else if(op=="D")y++;
        else y--;
        if(x<1||y<1||x>n||y>m)
        {
            cout<<"out of bounds!\n";
            continue;
        }
        auto l=f.find({x,y});
        if(l==f.end())
        {
            cout<<"vanquish!\n";
            f[{x,y}]=lo[s];
            lo[s]={x,y};
            cnt[s]++;
        }
        else
        {
            string tmp=fa[fi({x,y})];
            if(tmp==s)
            {
                cout<<"peaceful.\n";
                lo[s]={x,y};
            }
            else if(cnt[s]>cnt[tmp]||(cnt[s]==cnt[tmp]&&s>tmp))
            {
                cout<<s<<" wins!\n";
                cnt[s]+=cnt[tmp];
                lo.erase(tmp);
                f[fi({x,y})]=lo[s];
                lo[s]={x,y};
            }
            else
            {
                cout<<tmp<<" wins!\n";
                cnt[tmp]+=cnt[s];
                f[fi(lo[s])]={x,y};
                lo.erase(s);
            }
        }
    }
    return 0;
}
