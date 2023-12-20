#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	map<int,int>mp;
	int flag=1;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		mp[op]++;
	}
	int sum=mp.size();
	if(mp[0]!=0)
	 flag=0;
	auto pos1=mp.begin();
	auto pos2=mp.rbegin();
	if(pos1->first==-pos2->first && sum==2)
	 flag=0;
	if(flag)
	 cout<<"YES"<<endl;
	else
	 cout<<"NO"<<endl;
	return 0;
} 
