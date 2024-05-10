#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ull unsigned long long
using namespace std;
const int maxn=200005;
int x[maxn],y[maxn];
signed main()
{
	jiasu;
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>x[i]>>y[i];
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((abs(x[i]-x[j])+abs(y[i]-y[j]))%2==0)
			{
				sum+=max(abs(x[i]-x[j]),abs(y[i]-y[j]));
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
