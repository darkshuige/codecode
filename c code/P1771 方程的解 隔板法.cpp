#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10010;
const int mod=1000;
int c[1000][100][150];//前两位表示组合数，第三位表示这个数第i位的数
int ksm(int a,int n)
{
	int res=1;
	while(n)
	{
		if(n & 1) res=res*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return res;
}
void add(int c[],int a[],int b[])
{
	for(int i=0;i<150;i++)
	{
		c[i]+=a[i]+b[i];
		c[i+1]+=c[i]/10;
		c[i]%=10;	
	}
}
void getc(int n,int k) //组合数 递推法，因为k和n比较小
{
	for(int i=0;i<n;i++)
	 for(int j=0;j<=i && j<k;j++)
	  if(j==0) c[i][j][0]=1;
	  else add(c[i][j],c[i-1][j],c[i-1][j-1]);
}
signed main()
{
	int k,x;
	cin>>k>>x;
	int n=ksm(x%mod,x);
	getc(n,k);
	int i=150-1;
	while(c[n-1][k-1][i]==0) i--;
	while(i>=0) cout<<c[n-1][k-1][i--];
	cout<<endl;
	return 0;
}