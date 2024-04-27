#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
signed main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int sum=0;
	int nn=n+1>>1,mm=m+1>>1;
	for(int i=1;i<=k;i++)
	{
		int x,y; cin>>x>>y;
		int len=abs(x-nn)+abs(y-mm);
		if(len<=max(m/2,n/2)) sum++;
	}
	cout<<sum<<endl;
	return 0;
}