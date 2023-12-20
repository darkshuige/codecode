#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
int a[maxn];
signed main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	int pos1=0,pos2=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,ans=1e9;
	while(pos2<=n)
	{
		if(cnt1>=1 && cnt2>=1 && cnt3>=1 && cnt4>=k)
		{
			ans=min(ans,pos2-pos1+1);
			pos1++;
			if(a[pos1-1]==1) cnt1--;
			if(a[pos1-1]==2) cnt2--;
			if(a[pos1-1]==3) cnt3--;
			if(a[pos1-1]==4) cnt4--;
		}
		else
		{
			pos2++;
			if(a[pos2]==1) cnt1++;
			if(a[pos2]==2) cnt2++;
			if(a[pos2]==3) cnt3++;
			if(a[pos2]==4) cnt4++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
