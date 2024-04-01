#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244853;
const int maxn=300005;
int n,m,k;
vector<pair<int,int> >g[maxn];
int a[maxn];
map<pair<int,int>,int>cnt;
int ans1,ans2;
int flag;
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		 ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int gcd(int a,int b)
{
	if(a>b) swap(a,b);
	int t=a%b;
	while(t)
	{
		a=b;b=t;t=a%b;
	}
	return b;
}
void jia(int a1,int a2,int b1,int b2)
{
	if(a1==0 && a2==0)
	{
		ans1=b1,ans2=b2;
	}
	else
	{
		ans1=a1*b2+b1*a2;
		ans2=a2*b2;
	}
	int g=gcd(ans1,ans2);
	ans1/=g,ans2/=g;
}
void dfs(int p,int sum,int posi)
{
	if(p==k)
	{
		jia(ans1,ans2,sum,posi);
		flag=1;
		return ;
	}
	int s=cnt[{a[p],a[p+1]}];
	if(s==0) return ;
	for(auto v:g[a[p]])
	{
		if(v.first==a[p+1])
		{
			dfs(p+1,sum*10+v.second,posi*s);
		}
	}
}
signed main()
{
	jiasu;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
		cnt[{a,b}]++;
		cnt[{b,a}]++;
	}
	for(int i=1;i<=k;i++)
	 cin>>a[i];
	dfs(a[1],0,1);
	if(flag)
	 cout<<ans1*ksm(ans2,mod-2)%mod<<endl;
	else
	 cout<<"Stupid Msacywy!"<<endl;
	return 0;
}
