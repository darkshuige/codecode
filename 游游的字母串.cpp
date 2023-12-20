#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
signed main()
{
	jiasu;
	int maxn=INT_MAX;
	string s;
	cin>>s;
	for(char i='a';i<='z';i++)
	{
		int sum=0;
		for(int j=0;j<s.size();j++)
		{
			sum+=min(abs(s[j]-i),26-abs(s[j]-i));
		}
		maxn=min(maxn,sum);
	} 
	cout<<maxn<<endl;
	return 0;
} 
