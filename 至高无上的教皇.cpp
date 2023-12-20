#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=100005;
int a[maxn],res[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		double mm=-INF;
		for(int j=i+1;j<=n;j++)
		{
			double k=(double)(a[j]-a[i])/(double)(j-i);
			if(k>mm)
			{
				mm=k;
				res[i]++;
				res[j]++;	
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		 cout<<" ";
		cout<<res[i];
	}
	cout<<endl;
	return 0;
} 
