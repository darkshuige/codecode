#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int a[maxn];
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,x;
		cin>>n>>x;
		int sum=5*(n-x);
		a[0]=0;
		for(int k=1;k<=x;k++)
		 cin>>a[k];
		a[++x]=n+1;
		for(int i=1;i<=x;i++)
		{
			int l=a[i-1]+1,r=a[i]-1;
			for(int j=l;j<=r;j++)
			{
				if((j-1)%7==0 && j-l+1>=7)
				{
					sum-=50;
					j+=6;	
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
