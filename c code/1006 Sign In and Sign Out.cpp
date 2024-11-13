#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
struct node
{
	int t1,t2;
	string name;
}a[maxn];
int cmp1(node a,node b)
{
	return a.t1<b.t1;
}
int cmp2(node a,node b)
{
	return a.t2>b.t2;
}
signed main()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].name;
		char k;
		int aa,b,c; cin>>aa>>k>>b>>k>>c;
		a[i].t1=aa*3600+b*60+c;
		cin>>aa>>k>>b>>k>>c;
		a[i].t2=aa*3600+b*60+c;
	}
	sort(a,a+n,cmp1);
	cout<<a[0].name<<" ";
	sort(a,a+n,cmp2);
	cout<<a[0].name<<endl;
	return 0;
} 