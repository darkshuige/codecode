#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int a[maxn];
int cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,k;
		cin>>n>>k>>x;
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		int sum=0;
		for(int i=1;i<=k;i++)
		{
			for(int j=i;j<=n;j+=k)
			{
				sum+=(abs(a[j]-a[i]));
				if(a[j]>a[i])
				 a[i]=a[j];
				else
				 a[j]=a[i];
			}
		}
		if(sum>x)
		{
			cout<<-1<<endl;
		}
		else
		{
			x-=sum;
			sort(a+1,a+1+n,cmp);
			cout<<a[1]+x<<endl;
		}
	}
	return 0;
}
