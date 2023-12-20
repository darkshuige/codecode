#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int sum=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0' || s[i]=='6' || s[i]=='9')
		 sum++;
		else if(s[i]=='8')
		 sum+=2;
	}
	cout<<sum<<endl;
	return 0;
}
