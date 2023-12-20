#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	 while(a[i]!=i)
	 {
	 	swap(a[i],a[a[i]]);
	 	cnt++;
	 }
	cout<<cnt<<endl;
	return 0;
} 
