#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(flase),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int a[maxn];
signed main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	 a[i]=i;
	swap(a[n],a[k*2-1]);
	for(int i=1;i<k*2-1;i+=2)
	 swap(a[i],a[i+1]);
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		 cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
 
