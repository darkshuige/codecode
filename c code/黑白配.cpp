#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
signed main()
{
	jiasu;
	int t,n;
	cin>>t>>n;
	while(t--)
	{
		int a=0,b=0;
		for(int i=0;i<n;i++)
		{
			int op;
			cin>>op;
			if(op==1) a++;
			else b++;
		}
		cout<<abs(a-b)<<endl;
	}
	return 0;
}