#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f 
const int mod=998244353;
using namespace std;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		int sum=0;
		cin>>n;
		int flag=0; 
		for(int j=0;j<n;j++)
		{
			int op;
			cin>>op;
			if(op)
			{
				if(op>1 && flag==1)
				 sum=(sum*op)%mod;
				else
				{
					if(sum+op>1)
					 flag=1;
					sum=(sum+op)%mod;
				}
			}
		}
		cout<<sum%mod<<endl;
	}
	return 0;
}
