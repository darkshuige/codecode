#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int a[maxn],sum[maxn];
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		memset(sum,0,sizeof sum);
		string s="#",k;
		cin>>k;
		s+=k;
		if(s[1]=='1')
		 a[1]=1;
		else
		 a[1]=2;
		for(int i=2;i<s.size();i++)
		{
			if(s[i]==s[i-1])
			 a[i]=a[i-1]+2;
			else
			 a[i]=a[i-1]+1;
			sum[i]=a[i];
		}
		sum[1]=a[1];
		for(int i=2;i<s.size();i++)
		{
			if(!(s[i]=='0' && s[i-1]=='1'))
			{
				for(int k=i;k<s.size();k++)
				 a[k]-=2;
			}
			for(int k=i;k<s.size();k++)
			{
				sum[k]+=a[k];
			}
		}
		int ans=0;
		for(int i=0;i<s.size();i++)
		 ans+=sum[i];
		cout<<ans<<endl;
	}
	return 0;
}
