#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10005;
map<string,int>mp;
struct node
{
	int c,m,e;
	double a;
	string id;
	int rk[4];
}a[maxn];
int cmpa(node a,node b)
{
	return a.a>b.a;
}
int cmpc(node a,node b)
{
	return a.c>b.c;
}
int cmpm(node a,node b)
{
	return a.m>b.m;
}
int cmpe(node a,node b)
{
	return a.e>b.e;
}
char pt[4]={'A','C','M','E'};
signed main()
{
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		mp[s]=i;
		a[i].id=s;
		cin>>a[i].c>>a[i].m>>a[i].e;
		a[i].a=1.0*a[i].c*a[i].m*a[i].e/3;
	}
	sort(a,a+n,cmpa);
	for(int i=0;i<n;i++)
	{
		if(a[i].a==a[i-1].a && i!=0)
		 a[i].rk[0]=a[i-1].rk[0];
		else
		 a[i].rk[0]=i+1;
	}
	sort(a,a+n,cmpc);
	for(int i=0;i<n;i++)
	{
		if(a[i].c==a[i-1].c && i!=0)
		 a[i].rk[1]=a[i-1].rk[1];
		else
		 a[i].rk[1]=i+1;
	}
	sort(a,a+n,cmpm);
	for(int i=0;i<n;i++)
	{
		if(a[i].m==a[i-1].m && i!=0)
		 a[i].rk[2]=a[i-1].rk[2];
		else
		 a[i].rk[2]=i+1;
	}
	sort(a,a+n,cmpe);
	for(int i=0;i<n;i++)
	{
		if(a[i].e==a[i-1].e && i!=0)
		 a[i].rk[3]=a[i-1].rk[3];
		else
		 a[i].rk[3]=i+1;
	}
	while(m--)
	{
		string s; cin>>s;
		if(!mp.count(s)) cout<<"N/A"<<endl;
		else
		{
			int pos=0;
			while(a[pos].id!=s) pos++;
			int pp=0;
			for(int i=0;i<=3;i++)
			 if(a[pos].rk[i]<a[pos].rk[pp])
			  pp=i;
			cout<<a[pos].rk[pp]<<" "<<pt[pp]<<endl;;
		}
	}
	return 0;
} 