#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=120010;
int mi[200];
map<int,int>mp;
int a[maxn];
int ksm(int a,int n)
{
	int res=1;
	while(n)
	{
		if(n & 1) res*=a;
		a*=a;
		n>>=1;
	}
	return res;
}
void init()
{
	for(int i=0;i<=40;i++)
	 mi[i]=ksm(2,i);
}
signed main()
{
	jiasu;
	init();
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		for(int j=0;j<=40;j++)
		{
			if(mi[j]<=a[i]) continue;
			int yao=mi[j]-a[i];
			if(yao==a[i])
			{
				if(mp[a[i]]>1)
				{
				 	flag=1;
				 	break;
				}	
			}
			else
			 if(mp[yao]>=1)
			 {
			 	flag=1;
			 	break;
			 }
		}
		if(flag==0)
		 sum++;
	}
	cout<<sum<<endl;
	return 0;
} 
