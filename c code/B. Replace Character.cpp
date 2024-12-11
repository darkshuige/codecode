#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1005;
map<char,int>mp;
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		string s; cin>>s;
		for(int i=0;i<n;i++)
		 mp[s[i]]++;
		int ma=INT_MIN; int mi=INT_MAX;
		char maa,mii;
		for(auto k:mp)
		{
			if(k.second>ma)
			{
				ma=k.second;
				maa=k.first;
			}
			if(k.second<mi)
			{
				mi=k.second;
				mii=k.first;
			}
		}
		if(mii!=maa)
		 for(int i=0;i<n;i++)
		 {
			 if(s[i]==mii)
			 {
				 s[i]=maa;
				 break;
			 }	
		 }
		else
		{
			for(int i=0;i<n;i++)
			{
				if(s[i]!=maa)
				{
					s[i]=maa;
					break;
				}	
			}
		}
		cout<<s<<endl;
	}
	return 0;
} 
