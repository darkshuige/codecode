#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10005;
vector<pair<int,double> >a,b;
map<int,double>ans;
stack<pair<int,double> >st;
signed main()
{
	int k; cin>>k;
	for(int i=0;i<k;i++)
	{
		int a1; double a2;
		cin>>a1>>a2;
		a.push_back({a1,a2});
	}
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int a1; double a2;
		cin>>a1>>a2;
		b.push_back({a1,a2});
	}
	for(auto k1:a)
	{
		for(auto k2:b)
		{
			int da=k1.first+k2.first;
			double xiao=k1.second*k2.second;
			ans[da]+=xiao;
		}
	}
	for(auto k:ans)
	 if(k.second!=0)
	  st.push({k.first,k.second});
	cout<<st.size();
	while(!st.empty())
	{
		cout<<fixed<<setprecision(1)<<" "<<st.top().first<<" "<<st.top().second;
		st.pop();
	}
    cout<<endl;
	return 0;
} 