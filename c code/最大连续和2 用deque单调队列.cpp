#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=200005;
deque<int>de;
int a[maxn],b[maxn];
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(b,0,sizeof b);
	for(int i=1;i<=n;i++)
	 b[i]=b[i-1]+a[i];
	de.clear();
	int ma=INT_MIN;
	de.push_back(0);
	for(int i=1;i<=n;i++)
	{
		if(de.front()<i-m) de.pop_front();
		ma=max(ma,b[i]-b[de.front()]);
		while(!de.empty() && b[i]<=b[de.back()]) de.pop_back();
		de.push_back(i);
	}
	cout<<ma<<endl;
	return 0;
} 
