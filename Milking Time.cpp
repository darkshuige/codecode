#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define ll unsigned long long
#define inf 1<<30
using namespace std;
const int manx=1e3+5;
int dp[manx];
struct node{
    int l,r,w;
}a[manx];
bool cmp(node a,node b){
    return a.l<b.l;
}
int main()
{
    int n,m,r,t=1;
    while(scanf("%d%d%d",&n,&m,&r)!=EOF)
    {
        for(int i=1;i<=m;i++){
            cin>>a[i].l>>a[i].r>>a[i].w;
            a[i].r+=r;
        }
        sort(a+1,a+1+m,cmp);
        int ans=0;
        for(int i=1;i<=m;i++)
            dp[i]=a[i].w;
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;j++)
                if(a[j].l>=a[i].r)
                    dp[j]=max(dp[j],dp[i]+a[j].w);
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
