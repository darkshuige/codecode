#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;
int a[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	int ans=0,s1=0,s2=0;
	for(int i=1,j=0;i<=n;i++)
	{
		while(j<n && s1+a[j+1]==((s2)^(a[j+1])))
		{
			s1+=a[j+1];
			s2^=a[j+1];
			j++;
		}
		ans+=j-i+1;
		s1-=a[i];
		s2^=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
