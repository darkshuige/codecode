#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=600;
map<int,int>h,l;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++)
	{
		int a,b; cin>>a>>b;
		sum1+=4;
		int sum=0;
		if(h[a]>0) sum++;
		if(h[a]+1<=h[a-1]) sum++;
		if(h[a]+1<=h[a+1]) sum++;
		h[a]++;
		sum1-=sum*2;
		sum2+=4; 
		sum=0;
		if(l[b]>0) sum++;
		if(l[b]+1<=l[b-1]) sum++;
		if(l[b]+1<=l[b+1]) sum++;
		l[b]++;
		sum2-=sum*2;
		cout<<sum1<<" "<<sum2<<endl;
	}
	return 0;
}