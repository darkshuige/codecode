#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int n,x,k;
int dep(int n,int x,int k)
{
	int l=x,r=x;
	if(k<0) return 0;
	for(int i=0;i<k;i++)
	{
		l*=2;
		r=r*2+1;
		if(l>n) return 0;
	}
	return min(r,n)-l+1;
}
signed main()
{
    jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>k;
		int sum=0;
		sum+=dep(n,x,k);
		while(x/2)
		{
			k--;
			sum+=dep(n,x/2,k)-dep(n,x,k-1);
			x/=2;
		}
		cout<<sum<<endl;
	}    
    return 0;
}
