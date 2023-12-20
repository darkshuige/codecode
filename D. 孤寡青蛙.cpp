#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int pos=s.find("(.>__<.)");
		while(pos!=string::npos)
		{
			sum++;
			s.erase(pos,8);
			pos=s.find("(.>__<.)");
		}
	}
	cout<<sum<<endl;
	return 0;
} 
