#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=10005;
struct node
{
	int f;
	int w;
	int s;
	int sumsum;
};
struct cmp
{
	bool operator() (node a,node b)
	{
		if(a.sumsum!=b.sumsum)
		 return a.sumsum<b.sumsum;
		else
		 return a.w%2==1;
	}
};
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		node a[maxn];
		int n,k;
		cin>>n>>k;
		memset(a,0,sizeof (node)*maxn);
		a[1].w=0;
		for(int i=0;i<n-1;i++)
		{
			int l,r,w;
			cin>>l>>r;
			cin>>a[l].w;
			a[l].f=r;
			a[l].s++;;
			while(a[l].f!=1)
			{
				l=a[l].f;
				a[l].s++;
			}
		}
		priority_queue<node,vector<node>,cmp>q;
		for(int i=2;i<=n;i++)
		{
			a[i].sumsum=(a[i].s)*a[i].w;
			q.push(a[i]);
		}
		int ans=0;
		queue<node>q2;
		while(k && !q.empty())
		{
			node op=q.top();
			q.pop();
			while(op.w==1)
			{
				q2.push(op);
				op=q.top();
				q.pop();
				if(q.empty() && op.w==1)
				{
					q2.push(op);
					goto end;	
				}
			}
			op.w=ceil(op.w*1.0/2);
			op.sumsum=(int)op.s*op.w;
			q.push(op);
			k--;
		}
		while(!q.empty())
		{
			node op=q.top();
			ans+=op.sumsum;
			q.pop();
		}
		end:
		while(!q2.empty())
		{
			node op=q2.front();
			ans+=op.sumsum;
			q2.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
} 
