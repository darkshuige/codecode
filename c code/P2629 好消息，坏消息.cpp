#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=2000005;
deque<int>de;
int a[maxn];
signed main()
{
	jiasu;
	int n;
	memset(a,0,sizeof a);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n+1;i<=2*n-1;i++) a[i]=a[i-n];//断环为链 直接把前面的数再接在后面
	for(int i=1;i<2*n;i++) a[i]+=a[i-1]; //前缀和处理
	int res=0;
	de.push_back(0);
	for(int i=1;i<2*n;i++)//找到前缀和里面最小的一个点然后减去前面就能看是否大于0
	{
		while(!de.empty() && a[i]<=a[de.back()]) de.pop_back();
		de.push_back(i);
		if(de.front()<i-n+1) de.pop_front();
		if(de.back()>=n)
		 if(a[de.front()]-a[i-n]>=0)
		  res++;
	}
	cout<<res<<endl;
	return 0;
} 
