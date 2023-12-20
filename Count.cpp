#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
__int128 ksm(__int128 a,__int128 b)
{
	__int128 ans=1;
	while(b)
	{
		if(b&1)
		 ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
void scan(__int128 &x)// ‰»Î
{
	x=0;int f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
inline void print(__int128 x)
{
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
signed main()
{
	//jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		__int128 n,m,k,ans;
		scan(n),scan(m),scan(k);
		if(n==k)
		 ans=ksm(m,n);
		else
		 ans=ksm(m,n-k);
		print(ans);
		cout<<endl;
	}
}
