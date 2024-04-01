#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
signed main()
{
	jiasu;
	string s;
	cin>>s;
	for(int i=2;i<=s.size();i++)
	{
		for(int j=0;j<s.size() && j+i<=s.size();j++)
		{
			string cut(s,j,i);
			string cp=cut;
			reverse(cp.begin(),cp.end());
			if(cp==cut)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
} 
