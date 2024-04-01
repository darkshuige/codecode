#include <stack>
#include <map>
#include <queue>
#include <string>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include <algorithm>
#include <math.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<ll, ll> pii;
#define mem(a,x) memset(a,x,sizeof(a))
#define debug(x) cout << #x << ": " << x << endl;
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<=(b);++i)
#define repr(i,b,a) for(int i=int(b);i>=(a);--i)
const int maxn = 5e5 + 10;
#define inf 0x3f3f3f3f
#define sf scanf
#define pf printf
const int mod = 1e9 + 7;
struct node
{
    ll val,id;
} q[maxn];
bool cmp(node a,node b)
{
    return a.val<b.val;
}
ll vis[maxn];
ll n,p,cnt;
int main()
{
    ll t,T=0;
    cin>>t;
    while(t--)
    {
        cnt=0;
        scanf("%lld%lld",&n,&p);
        for(int i=1; i<=n; i++)
        {
            ll a,b;
            scanf("%lld%lld",&a,&b);
            q[++cnt].val= a;///为下面离散化标记
            q[cnt].id=i;
            q[++cnt].val= b;///为下面离散化标记
            q[cnt].id=i;
            vis[i]=0;
        }
        sort(q+1,q+1+cnt,cmp);///排序，按成绩大小排序
        ll top=1,res=0;///top表示第一个及格元素的下标 res表示最高分的下表
        ll now=0;///当下表示及格的人数
        while(now!=n)///先预处理一下，找到第一个满足 包含n个学生的下标
        {
            res++;
            if(vis[q[res].id]==0)///没出现过 人数+1
            {
                now++;
            }
            vis[q[res].id]++;///标记当前学生出现几次
        }
        now--;///因为下面要 res-- 所以先把这个pop掉
        ll ans=0;
        vis[q[res].id]--;
        res--;
        while(res<cnt)
        {
            res++;///后移一位
            if(vis[q[res].id]==0)///没在及格标记 几个人数++
                now++;
            vis[q[res].id]++;
            while(q[top].val*100<q[res].val*p)/// 及格分提高原及格的不及格了
            {
                if(vis[q[top].id]==1)///原就这一个分 就把这个人从及格表中pop掉
                {
                    now--;
                }
                vis[q[top].id]--;
                top++;///及格下标后移
            }
            ans=max(now,ans);///找到最大的
        }
        printf("Case #%lld: %lld\n",++T,ans);
    }

    return 0;
}

