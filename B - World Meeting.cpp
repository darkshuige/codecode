#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=48;
const int mod=998244353;
int a[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int w[1010],x[1010];
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>x[i];
	}
	int sum=0,max=0;
	for(int i=0;i<=24;i++)
	{
		sum=0;
		for(int j=1;j<=n;j++)
		{
			if((x[j]+i)%24<18&&(x[j]+i)%24>=9)
			{
				sum+=w[j];
			}
		}
		if(sum>max)
		{
			max=sum;
		}
	}
	cout<<max<<endl;
} 
