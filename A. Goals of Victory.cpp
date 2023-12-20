#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;
int ex[]={-1,+0,+1,-1};
int ey[]={+0,+1,+0,-1};
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int sum=0;
		for(int i=0;i<n-1;i++)
		{
			int op;
			cin>>op;
			sum+=op;
		}
		cout<<-sum<<endl;
	}
	return 0;
}
