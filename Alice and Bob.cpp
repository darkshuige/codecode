#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=3005;
int a[maxn],b[maxn]={0};
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=b[i-1]+a[i];
		}
		int pos=-1;
		for(int i=n;i>=1;i--)
		{
			if(b[n]-b[i-1]>b[i-1])
			{
				pos=i;
				break;
			}
		}
		int s=((n-pos+1)^pos);
		if(s)
		 cout<<"Alice"<<" "<<a[pos]<<endl;
		else
		 cout<<"Bob"<<" "<<a[pos]<<endl;
	}
	return 0;
}
