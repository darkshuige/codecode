#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
struct node
{
	int a,b;
}a[maxn];
int cmp(node a,node b)
{
	return a.a+a.b>b.a+b.b;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		 cin>>a[i].a>>a[i].b;
		sort(a,a+n,cmp);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			if(i%2==0)
			 sum+=a[i].a;
			else
			 sum-=a[i].b;
		}
		cout<<sum<<endl;
	}
	return 0;
}
