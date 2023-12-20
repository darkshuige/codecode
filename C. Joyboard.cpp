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
            q[++cnt].val= a;///Ϊ������ɢ�����
            q[cnt].id=i;
            q[++cnt].val= b;///Ϊ������ɢ�����
            q[cnt].id=i;
            vis[i]=0;
        }
        sort(q+1,q+1+cnt,cmp);///���򣬰��ɼ���С����
        ll top=1,res=0;///top��ʾ��һ������Ԫ�ص��±� res��ʾ��߷ֵ��±�
        ll now=0;///���±�ʾ���������
        while(now!=n)///��Ԥ����һ�£��ҵ���һ������ ����n��ѧ�����±�
        {
            res++;
            if(vis[q[res].id]==0)///û���ֹ� ����+1
            {
                now++;
            }
            vis[q[res].id]++;///��ǵ�ǰѧ�����ּ���
        }
        now--;///��Ϊ����Ҫ res-- �����Ȱ����pop��
        ll ans=0;
        vis[q[res].id]--;
        res--;
        while(res<cnt)
        {
            res++;///����һλ
            if(vis[q[res].id]==0)///û�ڼ����� ��������++
                now++;
            vis[q[res].id]++;
            while(q[top].val*100<q[res].val*p)/// ��������ԭ����Ĳ�������
            {
                if(vis[q[top].id]==1)///ԭ����һ���� �Ͱ�����˴Ӽ������pop��
                {
                    now--;
                }
                vis[q[top].id]--;
                top++;///�����±����
            }
            ans=max(now,ans);///�ҵ�����
        }
        printf("Case #%lld: %lld\n",++T,ans);
    }

    return 0;
}

