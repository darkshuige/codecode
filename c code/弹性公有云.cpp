#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
struct node
{
	int a,b,d,e,p;
	double c;
	int id;
};
int cmp(node a,node b)
{
	if(a.p!=b.p)
	 return a.p<b.p;
	else
	 return a.id<b.id;
}
int check(node a,node b)
{
	if(a.a>=b.a && a.b>=b.b && a.c>=b.c && a.d>=b.d && a.e>=b.e)
	 return 1;
	else
	 return 0;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		node op[550];
		node person[550];
		int price[550]={0};
		for(int i=0;i<n;i++)
		{
			op[i].id=i+1;
			cin>>op[i].a>>op[i].b>>op[i].c>>op[i].d>>op[i].e>>op[i].p;	
		}
		 
		sort(op,op+n,cmp);
		for(int i=0;i<m;i++)
		{
			cin>>person[i].a>>person[i].b>>person[i].c>>person[i].d>>person[i].e;
			for(int k=0;k<n;k++)
			{
				if(check(op[k],person[i]))
				{
					person[i].p=op[k].p;
					person[i].id=op[k].id;
					break;
				}
			}
		}
		for(int i=0;i<m;i++)
		 cout<<person[i].id<<endl;
	} 
	return 0;
}
