#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;//         利用约束条件，降维优化，令 i+j=x+y=k 表示走的步数
int f[maxn+maxn][maxn][maxn];//dp[k][i][x]表示一共走了k步，第一个人走到i行，第二个人走到x行
int a[maxn][maxn];
signed main()
{
    int n;
    cin>>n;
    int aa,b,c;
    memset(a,0,sizeof a);
    while(cin>>aa>>b>>c)
    {
        if(aa==0 && b==0 && c==0) break;
        a[aa][b]=c;
    }
    for(int k=2;k<=maxn+maxn;k++)//从2开始因为坐标从1,1开始算
    {
        for(int i=1;i<=n;i++)//第一个人走到了第几行
        {
            for(int x=1;x<=n;x++)//第二个人走到了第几行
            {
                int j=k-i,y=k-x;
                if(j<1 || j>n || y<1 || y>n) continue;
                int &t=f[k][i][x];
                t=max(max(f[k-1][i-1][x],f[k-1][i][x-1]),max(f[k-1][i-1][x-1],f[k-1][i][x]));
                if(i==x) t+=a[i][j];
                else t+=a[i][j]+a[x][y];
            }
        }
    }
    cout<<f[n+n][n][n]<<endl;
    return 0;
}