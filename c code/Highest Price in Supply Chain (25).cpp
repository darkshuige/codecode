#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
int root;
vector<int>son[maxn];
int ans[maxn];
int ma=-1;
void dfs(int now,int deep)
{
    if(deep>ma) ma=deep;
    ans[now]=deep;
    for(int k:son[now])
     dfs(k,deep+1);
}
signed main()
{
    int n;
    double p,r;
    while(cin>>n>>p>>r)
    {
        for(int i=0;i<n;i++) son[i].clear();
        ma=-1;
        for(int i=0;i<n;i++)
        {
            int a; cin>>a;
            son[a].push_back(i);
            if(a==-1) root=i;
        }
        dfs(root,0);
        int num=0;
        for(int i=0;i<n;i++)
         if(ans[i]==ma) num++;
        for(int i=0;i<ma;i++)
         p=p+p*r/100;
        cout<<fixed<<setprecision(2)<<p<<" "<<num<<endl;
    }
    return 0;
}
