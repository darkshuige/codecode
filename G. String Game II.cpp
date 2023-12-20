#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),couttie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,k;
		cin>>n>>k;
		int a[30]={0},b[30]={0};
		string s1,s2;
		cin>>s1>>s2;
		for(int i=0;i<n;i++)
		{
			a[s1[i]-'a']++;
			b[s2[i]-'a']++;
		}
		
	}
	return 0;
}
