#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=1005;
signed main()
{
	//jiasu;
	int a[maxn],b[maxn];
	int n;
	int sum1=0,sum2=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		sum1+=a[i];
	}
	a[n]=1;
	b[n]=100;
	sum2=sum1;
	sum2+=b[n];
	sum1+=a[n];
	sort(a,a+1+n);
	sort(b,b+1+n);
	sum1-=a[0],sum1-=a[n];
	sum2-=b[0],sum2-=b[n];
	printf("%.6lf %.6lf\n",(double)sum1/(n-1),(double)sum2/(n-1));
	return 0;
} 
