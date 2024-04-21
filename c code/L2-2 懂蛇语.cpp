#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
set<string>st[maxn];
map<string,int>mp;
struct node
{
	string s;
}ans[maxn];
int cmp(node a,node b)
{
	return a.s<b.s;
}
signed main()
{
	int n; cin>>n; getchar();
	int cnt=1; 
	for(int i=1;i<=n;i++)
	{
		string s;
		getline(cin,s);
		string suoxie="",now="";
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==' ' && now.size()>=1)
			{
				suoxie+=now[0];
				now="";
			}
			else if(s[i]!=' ')
			 now+=s[i];
		}
		suoxie+=now[0];
		if(!mp.count(suoxie))
		 mp[suoxie]=cnt++;
		st[mp[suoxie]].insert(s);
	}
	int q; cin>>q; getchar();
	while(q--)
	{
		string s;
		getline(cin,s);
		string suoxie="",now="";
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==' ')
			{
				suoxie+=now[0];
				now="";
			}
			else
			 now+=s[i];
		}
		suoxie+=now[0];
		if(st[mp[suoxie]].size()==0)
		{
			for(int i=0;i<s.size();i++)
			 cout<<s[i];
			cout<<endl;
		}
		else if(st[mp[suoxie]].size()==1)
		 cout<<*st[mp[suoxie]].begin()<<endl;
		else
		{
			int cnt=0;
			for(auto kk:st[mp[suoxie]])
			 ans[cnt++]={kk};
			sort(ans,ans+cnt,cmp);
			for(int i=0;i<cnt;i++)
			{
				if(i!=0) cout<<"|";
				cout<<ans[i].s;
			}
			cout<<endl;
		}
	}
	return 0;
}