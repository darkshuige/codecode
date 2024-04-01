#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=100005;
int f[maxn];
int w[maxn],v[maxn],c[maxn];
signed main()
{
	jiasu;
	char kk;
	int st1,st2,ed1,ed2;
	cin>>st1>>kk>>st2>>ed1>>kk>>ed2;
	int n,m;
	m=ed2+ed1*60-(st2+st1*60);
	cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		if(cc==0)//完全背包
		{
			w[cnt]=aa;
			v[cnt]=bb;
			c[cnt++]=cc;
		}
		else//不管01还是多重，直接二进制转
		{
			for(int j=1;j<=cc;j<<=1)
			{
				w[cnt]=j*aa;
				v[cnt]=j*bb;
				c[cnt++]=1;
				cc-=j;
			}
			if(cc)
			{
				w[cnt]=cc*aa;
				v[cnt]=cc*bb;
				c[cnt++]=1;
			}
		}
	}
	int ma=INT_MIN;
	memset(f,0,sizeof f);
	for(int i=0;i<cnt;i++)
	{
		if(c[i]==1)
		{
			for(int j=m;j>=w[i];j--)
			{
				f[j]=max(f[j],f[j-w[i]]+v[i]);	
				ma=max(ma,f[j]);			
			}
		}
		else
		{
			for(int j=w[i];j<=m;j++)
			{
				f[j]=max(f[j],f[j-w[i]]+v[i]);
				ma=max(ma,f[j]);
			}
		}
	}
	cout<<ma<<endl;
	return 0;
} 
