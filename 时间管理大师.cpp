#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100;
set<int>st;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int h,m;
		cin>>h>>m;
		int t=h*60+m;
		st.insert(t-1);
		st.insert(t-3);
		st.insert(t-5);
	}
	cout<<st.size()<<endl;
	for(auto k:st)
 	 cout<<k/60<<" "<<k%60<<endl;
	return 0;
} 
