#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=110000;
int ex[]={-1,+0,+1,-1};
int ey[]={+0,+1,+0,-1};
struct node
{
	int cost;
	int num;
}a[maxn];
int cmp(const node a,const node b)
{
	if(a.cost!=b.cost)
	 return a.cost<b.cost;
	else
	 return a.num>b.num;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,p;
		cin>>n>>p;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].num;
		}
		for(int i=0;i<n;i++)
		 cin>>a[i].cost;
		sort(a,a+n,cmp);
		int sum=0;
		int sumc=0;
		sum++;
		sumc+=p;
		int pos=0;
		while(sum<n)
		{
			while(a[pos].num==0) pos++;
			if(a[pos].cost<p)
			{
				a[pos].num--;
				sum++;
				sumc+=a[pos].cost;
			}
			else
			{
				sum++;
				sumc+=p;
			}
		}
		cout<<sumc<<endl;
	}
	return 0;
}
