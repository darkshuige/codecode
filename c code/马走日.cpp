#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
int ex[]={+1,-1,+1,-1,+2,-2,+2,-2};
int ey[]={+2,+2,-2,-2,+1,+1,-1,-1};
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		if(n>m) swap(n,m);
		if(n==1) cout<<1<<endl;
		else if(n==2) cout<<(m-1)/2+1<<endl;
		else if(n==3 && m==3)
		{
			cout<<8<<endl;
		}
		else
		 cout<<n*m<<endl;
	}
	return 0;
}