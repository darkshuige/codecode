#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
const int mod=100000000-3;
int c[maxn];
struct node
{
	int date,id;
}a[maxn],b[maxn];
int cmp(node a,node b)
{
	return a.date>b.date;
}
int n;
int s[maxn];
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int t)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		s[i]+=t;
	}
}
int query(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		ans+=s[i];
	}
	return ans;
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i].date;
    	a[i].id=i;
	}
	for(int i=1;i<=n;i++)
    {
    	cin>>b[i].date;
    	b[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++)
	 c[a[i].id]=b[i].id;
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		update(c[i],1);
		ans=(ans+query(c[i]-1))%mod;
	}
	cout<<ans<<endl;
    return 0;
}

