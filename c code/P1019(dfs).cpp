#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=25;
string a[maxn];
int ans,n,used[maxn];
void dfs(string s)
{
	ans=max(ans,(int)s.size());
	for(int i=0;i<n;i++)
	{
		int ls=s.size(),li=a[i].size();
		for(int j=1;j<ls && j<li;j++)
		{
			if(s.substr(ls-j)==a[i].substr(0,j) && used[i]<2)
			{
				used[i]++;
				dfs(s+a[i].substr(j));
				used[i]--;
			}
		}
	}
}
signed main()
{
	jiasu;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	string start="*";
	string s;
	cin>>s;
	start+=s;
	ans=1;
	memset(used,0,sizeof used);
	dfs(start);
	cout<<ans-1<<endl;
	return 0;
}
