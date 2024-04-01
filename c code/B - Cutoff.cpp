#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=110;
int a[maxn];
signed main()
{
    jiasu;
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n-1;i++)
     cin>>a[i];
    sort(a,a+n-1);
    int sum=0;
    for(int i=1;i<n-2;i++)
     sum+=a[i];
    if(sum>=x)
    {
    	cout<<0<<endl;
	}
	else if(sum+a[0]>=x)
	{
		cout<<0<<endl;
	}
	else if(sum+a[n-2]>=x)
	{
		cout<<x-sum<<endl;
	}
	else
	 cout<<-1<<endl;
    return 0;
}
