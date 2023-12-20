#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
map<int,string>mp;
int m;
string f(string s)
{
	int i=0,j=1,k=0;
	while(i<m && j<m)
	{
		for(k=0;k<=m && s[i+k]==s[j+k];k++);
		if(k==m)
		 break;
		if(s[i+k]>s[j+k])
		{
			i=i+k+1;
			if(i==j)
			 i++;
		}
		else
		{
			j=j+k+1;
			if(i==j)
			 j++;
		}
	}
	int pos=min(i,j);
	string ans="";
	for(int i=0;i<m;i++)
	 ans+=s[pos+i];
	return ans;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n>>m;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			string ans=f(s+s);
			mp[i]=ans;
		}
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin>>x>>y;
			if(mp[x]==mp[y])
			 cout<<"Yes"<<endl;
			else 
			 cout<<"No"<<endl;
		}
	}
	return 0;
} 
