#include<stdio.h>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<algorithm>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 2e9
using namespace std;
const int maxn=2000;
struct node
{
    double p1,p2,p3;
}a[maxn][maxn];
double f[maxn][maxn];//f[i][j]表示从i，j到nn所要的步数期望
signed main()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)
          cin>>a[i][j].p1>>a[i][j].p2>>a[i][j].p3;
        f[n][n]=0;
        for(int i=n;i>=1;i--)
        {
            for(int j=n;j>=1;j--)
            {
                if(i==n && j==n) continue;
                f[i][j]+=(f[i][j+1]*a[i][j].p2+f[i+1][j]*a[i][j].p3+2)/(1.0-a[i][j].p1);
            }
        }
        cout<<fixed<<setprecision(3)<<f[1][1]<<endl;
    }
    return 0;
} 