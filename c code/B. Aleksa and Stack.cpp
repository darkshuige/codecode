#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f
using namespace std;
const int maxn=500005;
int a[maxn];
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int pos=1;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			if(i!=0) cout<<" ";
			cout<<pos;
			pos+=2;
		}
		cout<<endl;
	} 
	return 0;
 } 
