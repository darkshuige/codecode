#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a[10];
		vector<int>ans;
		map<int,int>mp;
		for(int i=1;i<=4;i++)
		 cin>>a[i];
		mp[1]=3,mp[2]=4,mp[3]=1,mp[4]=2;
		for(int i=1;i<=4;i++)
		{
			while(a[i]!=1)
			{
				a[i]--;
				ans.push_back(mp[i]);
			}
		}
		cout<<ans.size()<<endl;
		if(ans.size()!=0)
		{
			for(int j=0;j<ans.size();j++)
			 cout<<ans[j]<<" ";
			cout<<endl;	
		}	
	}
	return 0;	
} 
