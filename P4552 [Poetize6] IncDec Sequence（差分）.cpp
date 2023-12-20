#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn]={0};
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	int cnt1=0,cnt2=0;
	for(int i=2;i<=n;i++)
	 if(b[i]>0)
	  cnt1+=b[i];
	 else if(b[i]<0)
	  cnt2+=-b[i];
	cout<<max(cnt1,cnt2)<<endl<<abs(cnt1-cnt2)+1<<endl;
	return 0;
} 
