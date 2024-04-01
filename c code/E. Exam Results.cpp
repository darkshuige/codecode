#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=500005;
int ex[]={-1,+0,+1,-1};
int ey[]={+0,+1,+0,-1};
struct node
{
	int val,id;
}a[maxn];
int vis[maxn];
int cmp(const node a,const node b)
{
	return a.val<b.val;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int cnt=1;cnt<=t;cnt++)
	{
		memset(vis,0,sizeof vis);
		int n,p;
		cin>>n>>p;
		for(int i=0;i<n*2;i+=2)
		{
			cin>>a[i].val>>a[i+1].val;
			a[i].id=i,a[i+1].id=i;
		}
		sort(a,a+2*n,cmp);
		int top=0,now=0,res=0;
		while(now<n)
		{
			if(vis[a[res].id]==0)
			 now++;
			vis[a[res].id]++;
			res++;
		}
		res--;
		now--,vis[a[res].id]--;
		res--;
		int ans=0;
		while(res<n*2)
		{
			res++;
			if(vis[a[res].id]==0)
			 now++;
			vis[a[res].id]++;
			while(a[top].val*100<a[res].val*p)
			{
				vis[a[top].id]--;
				if(vis[a[top].id]==0)
				{
					now--;
				}
				top++;
			}
			ans=max(ans,now);
		}
		cout<<"Case #"<<cnt<<": ";
		cout<<ans<<endl;
	} 
	return 0;
}
