#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=40005;
map<string,int>mp;
map<int,string>mp1;
vector<int>g[maxn];
signed main()
{
	jiasu;
	int n,k; cin>>n>>k;
	int ct=0;
	for(int i=0;i<k;i++)
	{
		int num,j; cin>>num>>j;
		while(j--)
		{
			string s; cin>>s;
			if(!mp.count(s))
			{
				mp1[ct]=s;
				mp[s]=ct++;
			}
			g[mp[s]].push_back(num);
		}
	}
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		if(mp.count(s))
		{
			int id=mp[s];
			sort(g[id].begin(),g[id].end());
			cout<<s<<" "<<g[id].size()<<" ";
			for(int l=0;l<g[id].size();l++)
			{
				if(l!=0) cout<<" ";
				cout<<g[id][l];
			}
			cout<<endl;	
		}
		else
		 cout<<s<<" 0"<<endl;
	}
	return 0;
} 
