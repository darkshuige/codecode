#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200;
int a[maxn][maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int l=1,r=1000000;
	int ans;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(mid*mid*mid<=n)
		{
			ans=mid;
			l=mid+1;
		}
		else
		 r=mid-1;
	}
	int res;
	for(int i=ans;i>=1;i--)
	{
		string s=to_string(i*i*i);
		string s2=s;
		reverse(s2.begin(),s2.end());
		if(s==s2)
		{
			res=i;
			break;
		}
	}
	cout<<res*res*res<<endl;
	return 0;
}