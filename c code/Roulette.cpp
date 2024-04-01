#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int mod=998244353;
int goal;
double sum;
queue<int>q;
int maxn=-1;
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
void f(int n,int x,int p)
{
	if(n>=goal)
	{
		q.push(p);
		maxn=max(maxn,p);
		return;
	}
	if(n<x)
	 return;
	f(n+x,1,p+1);
	f(n-x,x*2,p+1);
}
int exgcd(int a,int b,int &x,int &y)
{
	int r,t;
	if(b == 0)
	{
		r = a;
		x=1;y=0;
	}
	else
	{
		r = exgcd(b,a%b,x,y);
		t = x;
		x = y;
		y = t - (a/b)*y;
	}
	return r;
}
void solve(int a,int b,int n)
{
	int x,y;
	int d = exgcd(a,n,x,y);
	if(b % d > 0)
	{
		printf("no answer\n");
	}
	else
	{
		int e = (x*(b/d)) % n;
		for(int i = 1;i <= d;i++)
		{
			cout<<(e+i*n/d) % n<<endl;
		} 
	}
}
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	goal=n+m;
	int p=0;
	sum=0;
	f(n,1,p);
	int x=0;
	while(!q.empty())
	{
		int a=q.front();
		x=(x+(ksm(2,maxn-a))%mod)%mod;
		q.pop();
	}
	int y=ksm(2,maxn)%mod;
	solve(y,x,mod);
	return 0;
} 
