#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=110;
const int mod=998244353;
struct node
{
	int id;
	int sc;
}a[maxn];
int cmp(node a,node b)
{
	if(a.sc!=b.sc)
	 return a.sc>b.sc;
	else
	 return a.id<b.id;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		a[i].id=i;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='o')
			 a[i].sc++;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i!=1) cout<<" ";
		cout<<a[i].id;
	}
	cout<<endl;
	return 0;
}
