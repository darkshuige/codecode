#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
const int maxn=100005;
int s[505];
int ss[maxn];
struct node
{
	int a,b,pos;
	double val;
}no[maxn];
void init()
{
	for(int i=1;i<=500;i++)
	 s[i]+=s[i-1]+i;
}
int cmp(node a,node b)
{
	if(a.val!=b.val)
	 return a.val>b.val;
	else
	 return a.pos<b.pos;
}
signed main()
{
	jiasu;
	init();
	int t;
	cin>>t;
	int cnt=1;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>no[i].a>>no[i].b;
			no[i].pos=lower_bound(s+1,s+1+500,no[i].a)-s;
			no[i].val=(double)no[i].b/no[i].pos;
		}
		sort(no+1,no+1+n,cmp);
		memset(ss,0,sizeof ss);
		for(int i=1;i<=n;i++)
		 ss[i]+=ss[i-1]+no[i].b;
		int ans=0;
		for(int i=1;i<=n;i++)
		 ans+=no[i].pos*(ss[n]-ss[i-1]);
		cout<<"Case #"<<cnt<<": "<<ans<<endl;
		cnt++;
	}
    return 0;
} 
