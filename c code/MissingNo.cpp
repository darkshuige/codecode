#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(fasle),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=110;
int a[maxn];
signed main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		if(a[i+1]!=a[i]+1)
		{
			cout<<a[i]+1<<endl;
			break;
		}
	}
	return 0;
}
