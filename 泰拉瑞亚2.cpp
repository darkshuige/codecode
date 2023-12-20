#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int b[maxn]={0};
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
int cmpp(int a,int b)
{
	return a>b;
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
	sort(op,op+n,cmp);
	int k=0;
	int pos;
	for(pos=0;pos<n;pos++)
	{
		if(op[pos].b>=maxn)
		 b[k++]=op[pos].b;
		else
		 break;
	}
	sort(b,b+pos,cmpp);
	int cnt=0;
	while(h>0 && cnt<pos)
	 h-=b[cnt++];
	if(h>0)
	{
		if(h%maxn==0) cnt+=h/maxn;
		else cnt+=h/maxn+1;
	}
	cout<<cnt<<endl;
	return 0;
}
