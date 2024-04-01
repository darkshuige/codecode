#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1000005*3+6;
int s[maxn],vis[maxn],prim[maxn];
int a,m;
//威尔逊定理 (p-1)!===-1(mod p)是p为质数的充分必要条件
//推论
//若p是质数  	   (p-1)!+1===0(mod p)
//若p是大于4的合数 (p-1)!===0(mod p)
void get_d(int n)
{
	int cnt=1;
	for(int i=2;i<=n;i++)
	{
		if(vis[i]==0)
		 prim[cnt++]=i;
		for(int j=1;i*prim[j]<=n;j++)//越界中断
		{
			int m=i*prim[j];
			vis[m]=1;
			if(i%prim[j]==0)
			 break;
		}
	}
}
void init(int n)
{
	get_d(n);
	for(int i=2;i<n;i++)
	{
		s[i]+=s[i-1];
		if(vis[i]==0 && i>7 && (i-7)%3==0)
		 s[i]++;
	}
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	init(maxn);
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		cout<<s[k*3+7]<<endl;
	}
	return 0;
}