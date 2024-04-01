#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
int a[maxn]={0};
int b[maxn]={0};
signed main()
{
	jiasu;
	int n,k;
	cin>>n>>k;
	int sum=0;
	int op=1;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
		{
			b[op++]=a[i];
			b[op-1]+=b[op-2];
		}
		if(i!=2)
		 a[i]+=a[i-1];
	}
	if(k>=-b[op-1])
	{
		if(a[1]>=0 && -b[op-1]<=a[1])
		 cout<<n<<endl;
		else
		 cout<<n-1<<endl;
	}
	else
	{
		int pos=1;
		while(-b[pos]<=k)
		 pos++;
		if(a[1]>=0 && -b[pos-1]<=a[1])
		 cout<<pos<<endl;
		else
		 cout<<pos-1<<endl;
	}
	return 0;
}
