#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10010;
int prim[maxn],vis[maxn],cnt,c[maxn];
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(vis[i]==0) prim[cnt++]=i;
		for(int j=0;i*prim[j]<=n;j++)
		{
			vis[i*prim[j]]=1;
			if(i%prim[j]==0) break;
		}
	}
}
int get(int n,int p) // n!中p的个数
{
	int s=0;
	while(n) s+=n/p,n/=p;
	return s;
}
int getps(int n,int m,int p) //c中p的个数
{
	return get(n,p)-get(m,p)-get(n-m,p);
}
void mul(int c[],int p,int &len)//高精度乘法
{
	int t=0;
	for(int i=0;i<len;i++)
	{
		t+=c[i]*p;
		c[i]=t%10;
		t/=10;
	}
	while(t)
	{
		c[len++]=t%10;
		t/=10;	
	}
}
signed main()
{
	int n,m;
	cin>>n>>m;
	init(n);
	int len=1; c[0]=1;
	for(int i=0;i<cnt;i++)
	{
		int p=prim[i];
		int s=getps(n,m,p);
		while(s--) mul(c,p,len);
	}
	for(int i=len-1;i>=0;i--)
	 cout<<c[i];
	cout<<endl;
	return 0;
}