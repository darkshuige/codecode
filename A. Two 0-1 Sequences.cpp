#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int n,m; cin>>n>>m;
		string a,b; cin>>a>>b;
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int pos=0,flag=1;
		while(pos<m-1)
		{
			if(a[pos]!=b[pos])
			{
				flag=0;
				break;
			}
			pos++;
		}
		if(pos==m-1 && flag==1)
		{
			if(a[pos]!=b[pos])
			{
				flag=0;
				for(int i=pos;i<n;i++)
				{
					if(a[i]==b[pos])
					{
						flag=1;
						break;
					}	
				}
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}