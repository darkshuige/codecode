#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=1000005;
int a[maxn];
signed main()
{
	jiasu;
	int sum=0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	int l=0,r=0;
	sum=a[0];
	int cnt=0;
	while(1)
	{
		if(sum==m)
		{
			cnt++;
			if(r==n-1)
			 sum-=a[l++];
			else
			 sum+=a[++r];
		}
		if(l==r && r<n-1)
		{
			r++;
			sum+=a[r];
		}
		if(sum>m)
		{
			if(r==n-1 && sum<m)
		 	 break;	
		 	sum-=a[l++];
		}
		else if(sum<m)
		{
			if(r==n-1 && sum<m)
			 break;	
			sum+=a[++r];
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
