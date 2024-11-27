#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
int f[maxn];
map<string,int>mp;
vector<string>g[maxn];
signed main()
{
	int n; cin>>n;
	int ct=0;
	getchar();
	for(int i=0;i<n;i++)
	{
		string s,s1; cin>>s;
		getchar();
		for(int j=0;j<2;j++)
		{
			getline(cin,s1);
			if(!mp.count(s1))
			 mp[s1]=ct++;
			int k=mp[s1];
			g[k].push_back(s);	
		}
		cin>>s1; char c;
		while(1)
		{
			if(!mp.count(s1))
			 mp[s1]=ct++;
			int k=mp[s1];
			g[k].push_back(s);
			c=getchar(); if(c=='\n') break;
			cin>>s1;
		}
		for(int j=0;j<2;j++)
		{
			getline(cin,s1);
			if(!mp.count(s1))
			 mp[s1]=ct++;
			int k=mp[s1];
			g[k].push_back(s);	
		}
	}
	int p; cin>>p;
	for(int i=1;i<=p;i++)
	{
		string s; cin>>s; string ss=s;
		getchar();
		getline(cin,s);
		cout<<ss<<" "<<s<<endl;	
		if(mp.count(s))
		{
			int k=mp[s];
			sort(g[k].begin(),g[k].end());
			for(auto k:g[k])
		  	 cout<<k<<endl;
		}
		else
		 cout<<"Not Found"<<endl;
	}
	return 0;
} 