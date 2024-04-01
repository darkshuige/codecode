#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
vector<int>g[maxn];
int a[maxn],sum[maxn]={0};
signed main()
{
    jiasu;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	char k;
    	cin>>k;
    	a[i]=k-'0';
	}
    for(int i=0;i<n-1;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	g[a].push_back(b);
	}
	for(int i=n;i>=1;i--)
	{
		if(g[i].size()==0 && a[i]==1) continue;
		else if(g[i].size()!=0)
		{
			for(auto k:g[i])
			{
				sum[i]+=sum[k];
				if(a[k]==1)
				 sum[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()==0) cout<<0<<endl;
		else cout<<sum[i]<<endl;
	}
    return 0;
}
