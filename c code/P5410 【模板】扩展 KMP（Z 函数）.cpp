#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ull unsigned long long
using namespace std;
const int maxn=2e7+5;
int z[maxn]={0},p[maxn]={0};
char t[maxn],s[maxn];
void get_z(char s[],int n)
{
	z[1]=n;
	for(int i=2,l,r=0;i<=n;i++)
	{
		if(i<=r) //在盒内的情况
		 z[i]=min(z[i-l+1],r-i+1);
		while(s[1+z[i]]==s[i+z[i]])//暴力盒外 
		 z[i]++;
		if(z[i]+i-1>r)//更新盒子 
		{
			l=i;
			r=z[i]+i-1;
		}
	}
}
void get_p(char s[],int n,char t[],int m)
{
	for(int i=1,l,r=0;i<=m;i++)
	{
		if(i<=r)
		 p[i]=min(z[i-l+1],r-i+1);
		while(1+p[i]<=n && i+p[i]<=m && s[1+p[i]]==t[i+p[i]])
		 p[i]++;
		if(i+p[i]-1>r)
		{
			l=i;
			r=i+p[i]-1;
		}
	}
}
signed main()
{
	jiasu;
	cin>>t+1>>s+1;
	int n=strlen(t+1),m=strlen(s+1);
	get_z(s,m);
	get_p(s,m,t,n);
	int ans1=0,ans2=0;
	for(int i=1;i<=m;i++)
	 ans1^=1LL*i*(z[i]+1);
	for(int i=1; i<=n; i++)
     ans2^=1LL*i*(p[i]+1);
   cout<<ans1<<endl<<ans2;
	return 0;
}
