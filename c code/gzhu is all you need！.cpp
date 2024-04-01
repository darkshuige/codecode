#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
const int maxn=600;
char a[maxn][maxn];
map<char,int>mp;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	string s;
	cin>>s;
	int sum=0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(sum>0)
		 sum--;
		else
		{
			ans++;
			mp[s[i]]++;
			if(mp['g']>0 && mp['z']>0 && mp['h']>0 && mp['u']>0)
			{
				sum+=mp['g']+mp['z']+mp['h']+mp['u'];
				mp['g']=0;mp['z']=0;mp['h']=0;mp['u']=0;
			}
		}
	}
	cout<<ans<<endl;
    return 0;
} 
