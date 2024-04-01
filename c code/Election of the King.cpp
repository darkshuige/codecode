#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
struct node
{
	int date,id;
}a[maxn];
int cmp(node a,node b)
{
	return a.date<b.date;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].date;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	int ll=1,rr=n;
	while(ll<rr)
	{
		int sum1=0,sum2=0;
		int l=ll,r=rr;
		int ans=-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(a[rr].date-a[mid].date>=a[mid].date-a[ll].date)
			{
				ans=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		sum2=ans-ll+1;
		sum1=rr-ans;
		if(sum1>sum2)
		 ll++;
		else
		 rr--;
	}
	cout<<a[ll].id<<endl;
	return 0;
}
