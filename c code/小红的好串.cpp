#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=100005;
char s[maxn];
int r[maxn],e[maxn],d[maxn];
int ask(int t,int a,int b,int c1,int c2)
{
	int rr=r[c1]-r[a-1];
	int ee=e[c2]-e[c1];
	int dd=d[b]-d[c2];
	return t-(rr+ee+dd);
}
signed main()
{
	jiasu;
	int n,q; cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		r[i]=r[i-1]+(s[i]=='r');
		e[i]=e[i-1]+(s[i]=='e');
		d[i]=d[i-1]+(s[i]=='d');
	}
	while(q--)
	{
		int l,r; cin>>l>>r;
		int len=r-l+1;
		int z=len/3;
		int c1=l+z-1,c2=l+z*2-1,res=LLONG_MAX;
		if(len<3)
		{
			cout<<0<<endl;
			continue;
		}
		if(len%3==0)
		 res=min(res,ask(len,l,r,c1,c2));
		else if(len%3==1)
		{
			res=min(res,ask(len,l,r,c1,c2));
			res=min(res,ask(len,l,r,c1+1,c2+1));
			res=min(res,ask(len,l,r,c1,c2+1));
		}
		else if(len%3==2)
		{
			res=min(res,ask(len,l,r,c1,c2+1));
			res=min(res,ask(len,l,r,c1+1,c2+1));
			res=min(res,ask(len,l,r,c1+1,c2+2));
		}
		cout<<res<<endl;
	}
	return 0;
}

