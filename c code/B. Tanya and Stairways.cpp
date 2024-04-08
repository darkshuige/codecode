#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=1000055;
vector<int>v;
signed main()
{
	jiasu;
	int n; cin>>n;
	int now=1,pre=1;
	for(int i=0;i<n;i++)
	{
		cin>>now;
		if(now==1 && i!=0)
		{
			v.push_back(pre);
			now=1; pre=now;
		}
		else
		 pre=now;
	}
	v.push_back(now);
	cout<<v.size()<<endl;
	for(auto k:v)
		cout<<k<<" ";
	return 0;
} 
