#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
int a[600005],pos[600005];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int l=300000,r=300000+n;
	for(int i=300000;i<300000+n;i++)
	{
		cin>>a[i];
		pos[a[i]]=i;
	}
	int p;
	cin>>p;
	for(int i=0;i<p;i++)
	{
		string s;
		int op;
		cin>>s>>op;
		if(s=="FIRST")
		{
			a[pos[op]]=-1;
			pos[op]=--l;
			a[pos[op]]=op;
		}
		else if(s=="LAST")
		{
			a[pos[op]]=-1;
			pos[op]=r++;
			a[pos[op]]=op;
		}
	}
	int cnt=0;
	for(int i=l;i<r;i++)
	{
		if(a[i]!=-1)
		{
			if(cnt!=0)
			 cout<<" ";
			cout<<a[i];	
			cnt++;
		}
	}
	cout<<endl;
	return 0;
} 
