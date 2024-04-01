#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000005;
const int mod=998244353;
vector<int>v;
int a[maxn];
signed main()
{
	jiasu;
	int m,k;
	cin>>m>>k;
	cin>>a[1];
	v.push_back(1);
	for(int i=2;i<=m;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])
		 v.push_back(i);
	}
	int pos=1;
	for(pos;pos<v.size();pos++)
	{
		if(pos!=1)
		 cout<<" ";
		cout<<-1;
	}
	for(pos;pos<m;pos++)
	{
		
	}
	return 0;
}
