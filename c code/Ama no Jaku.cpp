#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=2005;
char a[maxn][maxn];
signed main()
{
	jiasu;
	map<string,int>mp1,mp2;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		mp1[a[i]]++;	
	}
	for(int i=0;i<n;i++)
	{
		string s="";
		for(int j=0;j<n;j++)
		{
			s+=a[j][i];
		}
		mp2[s]++;
	}
	if(mp1.size()<=2 && mp2.size()<=2)
	{
		if(mp1.size()==2 && mp2.size()==2)
		{
			int sum1=0,sum2=0;
			for(auto it=mp1.begin();it!=mp1.end();it++)
			{
				string s=it->first;
				for(int i=0;i<s.size();i++)
				 sum1+=(s[i]-'0');
			}
			for(auto it=mp2.begin();it!=mp2.end();it++)
			{
				string s=it->first;
				for(int i=0;i<s.size();i++)
				 sum2+=(s[i]-'0');
			}
			if(sum1!=n || sum2!=n)
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		int ans1=maxn,ans2=maxn;
		if(mp1.size()==1)
		 ans1=0;
		else
		{
			for(auto it=mp1.begin();it!=mp1.end();it++)
			{
				ans1=min(ans1,it->second);
			}	
		}
		if(mp2.size()==1)
		 ans2=0;
		else
		{
			for(auto it=mp2.begin();it!=mp2.end();it++)
			{
				ans2=min(ans2,it->second);
			}	
		}
		cout<<ans1+ans2<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}
