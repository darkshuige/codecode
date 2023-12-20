#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int a[maxn]; 
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	sort(a,a+n);
	int s=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]>s)
		 break;
		else
		 s+=a[i];
	}
	cout<<s<<endl;
	return 0;
}
