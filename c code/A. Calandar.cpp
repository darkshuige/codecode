#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200;
string a[]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
string b[]={"Friday","Thursday","Wednesday","Tuesday","Monday"};
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int y1,m1,d1; cin>>y1>>m1>>d1;
		string s; cin>>s;
		int y2,m2,d2; cin>>y2>>m2>>d2;
		int pre=y1*365+m1*30+d1;
		int now=y2*365+m2*30+d2;
		if(now>=pre)
		{
			int k=(now-pre)%5;
			int i;
			for(i=0;i<5;i++)
			 if(a[i]==s) break;
			cout<<a[(i+k)%5]<<endl;
		}
		else
		{
			int k=(pre-now)%5;
			int i;
			for(i=0;i<5;i++)
			 if(b[i]==s) break;
			cout<<b[(i+k)%5]<<endl;
		}
	}	
	return 0;
}