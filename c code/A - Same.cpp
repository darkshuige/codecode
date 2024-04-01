#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000050;
const int mod=998244353;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int flag=1;
	int op;
	cin>>op;
	for(int i=0;i<n-1;i++)
	{
		int sb;
		cin>>sb;
		if(sb!=op)
		 flag=0;
	}
	if(flag==1)
	 cout<<"Yes"<<endl;
	else
	 cout<<"No"<<endl; 
	return 0;
}
