#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;
const int mod=998244353;
int a[maxn];
int cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	jiasu;
	int y,n,m;
	cin>>y>>n>>m;
	for(int i=0;i<m;i++)
	 cin>>a[i];
	sort(a,a+m,cmp);
	int sum=0;
	while(y>0)
	{
		if(y<=n)
		{
			sum++;
			break;
		}
		if(y<=2*n)
		{
			sum+=2;
			break;
		}
		int flag=0;
		for(int i=0;i<m;i++)
		{
			if(a[i]<=y && a[i]!=1)
			{
				if(y%a[i]==0)
				{
					y/=a[i];
					sum++;
					flag=1;
					break;	
				}
				else if(y%a[i]<=n)
				{
					y/=a[i];
					sum+=2;
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
		{
			y-=n;
			sum++;
		}
		if(y<=n)
		{
			sum++;
			break;
		}
		if(y<=2*n)
		{
			sum+=2;
			break;
		}
	}
	cout<<sum<<endl;
	return 0;
}
