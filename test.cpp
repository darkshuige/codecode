#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 200005;
int cost[maxn];
int ma[maxn];
bool flag[maxn];
int f[maxn];
int find2(int x) 
{
    if (f[x] != x) 
    {
        f[x] = find2(f[x]);
    }
    return f[x];
}
void unite2(int x, int y) 
{
    int rootX = find2(x);
    int rootY = find2(y);
    if (rootX != rootY) 
    {
        f[rootY] = rootX;
        ma[rootX] = max(ma[rootX], ma[rootY]);
    }
}
set<pair<int,int> >st;
vector<int>g[maxn];
signed main() 
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> cost[i];
        f[i]=i;
        ma[i] = cost[i];
    }
    for (int i = 0; i < m; ++i) 
    {
        cin >> x >> y;
        st.insert({x,y});
        if(st.count({y,x}))
         unite2(x,y);
    }
    int mii = 0, maa = 0;
    memset(flag,0,sizeof flag);
    for (int i = 1; i <= n; ++i) 
    {
        int root = find2(i);
        if (!flag[root]) 
        {
            flag[root] = true;
            maa+= ma[root]; 
        }
    }
    
    cout << mii << " " << maa << endl;
    return 0;
}
