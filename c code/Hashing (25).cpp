#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1005;
map<int,int>mp;
vector<string>ans;
int isp(int a)
{
	if(a<=1) return 0;
	for(int i=2;i<a;i++)
	 if(a%i==0) return 0;
	return 1;
}
signed main()
{
	int m,n; cin>>m>>n;
	mp.clear();
	while(isp(m)==0)
	 m++;
	for(int i=0;i<n;i++)
	{
		if(i!=0) ans.push_back(" ");
		int j,k; cin>>k;
		for(j=0;j<m;j++)
		{
			int pos=(k+j*j)%m;
			if(!mp.count(pos))
			{
				ans.push_back(to_string(pos));
				mp[pos]++;
				break;
			}
		}
		if(j==m) ans.push_back("-");
	}
	for(auto k:ans)
	 cout<<k;
	cout<<endl;
	return 0;
}