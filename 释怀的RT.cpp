#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=1000005;
int a[maxn],c[maxn]={0};
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[max((int)1,i-a[i])]++;
		c[i]--;
		c[i+1]++;
		if(i+a[i]+1<=n)
		 c[i+a[i]+1]--;
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		flag+=c[i];
		if(flag>0)
		 sum++;
	}
	cout<<sum<<endl;
	return 0;
} 
