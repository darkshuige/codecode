#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=500;
typedef vector<int>VI;
VI res(maxn),a(maxn);
VI mul(VI a,VI b)
{
	VI t(maxn*2);
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
		{
			t[i+j]+=a[i]*b[j];
			t[i+j+1]+=t[i+j]/10;
			t[i+j]%=10;
		}
	}
	return t;
}
void skm(int n)
{
	res[0]=1,a[0]=2;
	while(n)
	{
		if(n & 1) res=mul(res,a);
		a=mul(a,a);
		n>>=1;
	}
	res[0]--;
}
signed main()
{
	int n;
	cin>>n;
	skm(n);
	cout<<(int)(n*log10(2))+1<<endl;
	for(int i=0, k=499; i<10; i++)
	{
		for(int j=0; j<50; j++, k--)
		 printf("%d",res[k]);
		puts("");
	}
	return 0;
}