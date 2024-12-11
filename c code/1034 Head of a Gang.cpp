#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2005;
vector<int>g[maxn];
int n,k;
map<string,int>mp1;
map<int,string>mp2;
int sum[maxn];
int vis[maxn];
vector<pair<string,int> >ans;
int num,total,ma,pos;
void dfs(int now)
{
	if(sum[now]>ma)
	{
		ma=sum[now];
		pos=now;
	}
	vis[now]=1;
	num++; total+=sum[now];
	for(auto k:g[now])
	{
		if(vis[k]) continue;
		dfs(k);
	}
}
signed main()
{
	cin>>n>>k;
	int ct=0;
	for(int i=0;i<n;i++)
	{
		string a,b; cin>>a>>b;
		int t; cin>>t;
		if(!mp1.count(a))
		{
			mp2[ct]=a;
			mp1[a]=ct++;
		} 
		if(!mp1.count(b))
		{
			mp2[ct]=b;
			mp1[b]=ct++;
		}
		g[mp1[a]].push_back(mp1[b]);
		g[mp1[b]].push_back(mp1[a]);
		sum[mp1[a]]+=t; sum[mp1[b]]+=t;
	}
	memset(vis,0,sizeof vis);
	for(int i=0;i<mp1.size();i++)
	{
		if(vis[i]) continue;
		num=0,total=0,pos=-1,ma=INT_MIN;
		dfs(i);
		total/=2;
		if(total>k && num>=3)
		 ans.push_back({mp2[pos],num});
	}
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(auto k:ans)
	{
		cout<<k.first<<" "<<k.second<<endl;
	}
	return 0;
} 
