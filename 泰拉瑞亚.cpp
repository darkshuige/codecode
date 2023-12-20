#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
struct node
{
	int a,b;
};
int cmp1(node a,node b)
{
	if(a.a!=b.a)
	 return a.a>b.a;
	else
	 return a.b>b.b;
}
int cmp(node a,node b)
{
	if(a.b!=b.b)
	 return a.b>b.b;
	else
	 return a.a>b.a;
}
signed main()
{
	jiasu;
	int n,h;
	cin>>n>>h;
	node op[maxn];
	for(int i=0;i<n;i++)
	 cin>>op[i].a>>op[i].b;
	sort(op,op+n,cmp1);
	int maxn=op[0].a;
	int pos=0;
	int sum=0;
	int flag=0;
	while(op[pos].b>=maxn && pos<n)
	{
		sum+=op[pos].b;
		pos++;	
		if(sum>=h)
		 flag=1;
	}
	int cnt;
	if(flag==1)
	{
		int sum=0;
		sort(op,op+pos,cmp);
		for(int i=0;i<pos;i++)
		{
			sum+=op[i].b;
			if(sum>=h)
			{
				cnt=i+1;
				break;
			}	
		}
	}
	else
	{
		h-=sum;
		cnt=pos;
		if(h>0)
		{
			if(h%maxn==0)
			 cnt+=h/maxn;
			else
			 cnt+=h/maxn+1;	
		}	
	}
	cout<<cnt<<endl;
	return 0;
}
