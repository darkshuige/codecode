#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=110;
vector<int>v[maxn];
int sc[maxn];
int sum[maxn];
int ma;
int cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	 cin>>sc[i];
	ma=INT_MIN;
	memset(sum,0,sizeof sum);
	for(int i=1;i<=n;i++)
	{
		sum[i]+=i;
		string s;
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='o')
			 sum[i]+=sc[j];
			else
			 v[i].push_back(sc[j]);
		}
		ma=max(ma,sum[i]);
	}
	for(int i=1;i<=n;i++)
	{
		sort(v[i].begin(),v[i].end(),cmp);
		int cnt=0;
		for(auto op:v[i])
		{
			if(sum[i]>=ma) break;
			sum[i]+=op;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
