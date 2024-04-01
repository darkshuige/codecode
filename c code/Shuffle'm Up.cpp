#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
map<string,int>mp;
const int maxn=100005;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int ct=1;ct<=t;ct++)
	{
		mp.clear();
		int n;
		cin>>n;
		string a,b,c;
		cin>>a>>b>>c;
		string now="";
		int sum=1;
		for(int i=0;i<n;i++)
		{
			now+=b[i];
			now+=a[i];
		}
		int flag=1;
		while(1)
		{
			if(mp.count(now))
			{
				flag=0;
				break;
			}
			mp[now]=sum++;
			if(now==c) break;
			a=now.substr(0,n);
			b=now.substr(n,n);
			now="";
			for(int i=0;i<n;i++)
			{
				now+=b[i];
				now+=a[i];
			}
		}
		cout<<ct<<" ";
		if(flag==0)
		 cout<<-1<<endl;
		else
		 cout<<mp[c]<<endl;
	}
	return 0;
}
