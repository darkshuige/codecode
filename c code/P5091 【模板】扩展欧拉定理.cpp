#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100000005;
string b;
int a,m;
//扩展欧拉定理
//a^b===a^b  b<phi(m) (mod m)
//a^b===a^(b mod phi(m) + phi(m) ) (mod m)
int init(int n)
{ //试除法求欧拉函数
	int res = n;
	for(int i=2; i*i<=n; i++)
	{
		if(n%i == 0)
		{
			res = res/i*(i-1);
			while(n%i == 0) n /= i;
		}
	}
	if(n>1) res = res/n*(n-1);
	return res;
}
int depow(int phi)//降幂
{
	int now=0,flag=0;
	for(int i=0;i<b.size();i++)
	{
		now=now*10+(b[i]-'0');
		if(now>=phi) flag=1,now%=phi;
	}
	if(flag) now+=phi;
	return now;
}
int ksm(int a,int k)
{
	int res=1;
	while(k)
	{
		if(k & 1)
		 res=(res*a)%m;
		a=(a*a)%m;
		k>>=1;
	}
	return res%m;
}
signed main()
{
	jiasu;
		
	cin>>a>>m>>b;
	int phi=init(m);//先计算phi(m)
	int bb=depow(phi);
	cout<<ksm(a,bb)<<endl;
	return 0;
}