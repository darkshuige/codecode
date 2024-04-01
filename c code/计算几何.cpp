#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int M=1000000000;
const int maxn=100005;
struct node
{
	int x,y,id;
}a[maxn];
int cmp(node a,node b)
{
	if(a.x!=b.x)
	 return a.x<b.x;
	else
	 return a.y<b.y;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].id=i;
	}
	 
	sort(a+1,a+1+n,cmp);
	cout<<n/2<<endl;
	int pos=1;
	for(int cnt=0;cnt<n/2;cnt++)
	{
		cout<<a[pos].id<<" "<<a[pos+1].id<<endl;
		pos+=2;
	}
    return 0;
} 
