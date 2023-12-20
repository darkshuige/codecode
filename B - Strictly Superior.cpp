#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
struct node
{
	int p,c;
	vector<int>v;
	bool flag[200];
};
int check(node i,node j)
{
	for(int op=0;op<i.c;op++)
	{
		if(j.flag[i.v[op]]==0)
		 return 0;
	}
	return 1;
}
int check2(node i,node j)
{
	for(int op=0;op<j.c;op++)
	{
		if(i.flag[j.v[op]]==0)
		 return 1;
	}
	return 0;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	node a[200];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].p>>a[i].c;
		for(int j=1;j<=a[i].c;j++)
		{
			int x;
			cin>>x;
			a[i].v.push_back(x);
			a[i].flag[x]=1;
		}
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i].p>=a[j].p)
			{
				if(check(a[i],a[j]))
				{
					if(a[i].p>a[j].p || check2(a[i],a[j]))
					{
						flag=1;
						goto end;
					}
				}
			}
		}
	}
	end:
	if(flag==1)
	 cout<<"Yes"<<endl;
	else 
	 cout<<"No"<<endl;
	return 0;
} 
