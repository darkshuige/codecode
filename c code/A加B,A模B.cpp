#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f 
using namespace std;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,m;
		cin>>n>>m;
		int flag=0;
		if(m<n-m)
		{
			cout<<m<<" "<<n-m<<endl;
			continue;
		}
//		for(int b=1;b<=n/2;i++)
//		{
//			int j=n-i;
//			if(j%i==m)
//			{
//				cout<<j<<" "<<i<<endl;
//				flag=1;
//				break;	
//			}
//		}
//		if(flag==0)
		 cout<<-1<<endl;
	}
	return 0;
}
