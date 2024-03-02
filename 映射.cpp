#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn],c[maxn];
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(c,-1,sizeof c);
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		int flag=1;
		for(int i=0;i<n;i++)
		{
			if(c[a[i]]==-1)
			 c[a[i]]=b[i];
			else
			{
				if(c[a[i]]!=b[i])
				{
					flag=0;
					break;	
				}
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}