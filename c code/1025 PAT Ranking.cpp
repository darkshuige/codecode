#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
struct node
{
	string name;
	int score;
	int lo_rank,global_rank;
	int local;
}a[400*105],b[400];
int cmp(node a,node b)
{
	if(a.score!=b.score)
	 return a.score>b.score;
	else
	 return a.name<b.name;
}
signed main()
{
	int n; cin>>n;
	int ct=1;
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>b[j].name>>b[j].score;
			b[j].local=i;
		}
		sort(b+1,b+1+k,cmp);
		for(int i=1;i<=k;i++)
		{
			b[i].lo_rank=i;
			if(i!=1)
			{
				if(b[i].score==b[i-1].score)
				 b[i].lo_rank=b[i-1].lo_rank;
			}
			a[ct++]=b[i];
		}
	}
	sort(a+1,a+ct,cmp);
	for(int i=1;i<=ct;i++)
	{
		a[i].global_rank=i;
		if(i!=1)
		{
			if(i!=1)
			{
				if(a[i].score==a[i-1].score)
				 a[i].global_rank=a[i-1].global_rank;
			}
		}
	}
	cout<<ct-1<<endl;
	for(int i=1;i<ct;i++)
	{
		cout<<a[i].name<<" "<<a[i].global_rank<<" "<<a[i].local<<" "<<a[i].lo_rank<<endl;
	}
	return 0;
} 