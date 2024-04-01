#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=20;
struct node
{
	int de,ti,num;
}a[maxn];
int cmp(node a,node b)
{
	if(a.de==b.de)
	 if(a.ti==b.ti)
	  return a.num<b.num;
	 else
	  return a.ti<b.ti;
	else
	 return a.de<b.de;
}
map<int,string>mp;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		mp.clear();
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			string s; int aa,bb;
			cin>>s>>aa>>bb;
			mp[i]=s;
			a[i]={aa,bb,i};	
		}
		sort(a,a+n,cmp);
		int now=0,sum=0;
		for(int i=0;i<n;i++)
		{
			now+=a[i].ti;
			if(now>a[i].de) sum+=now-a[i].de;
		}
		cout<<sum<<endl;
		for(int i=0;i<n;i++)
		 cout<<mp[a[i].num]<<endl;
	}
	return 0;
}