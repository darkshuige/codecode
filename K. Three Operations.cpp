#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int x,a,b;
		cin>>x>>a>>b;
		int sum=0;
		while(x>0)
		{
			if(x-1<=(x+a)/2 && x-1<=(int)sqrt(x+b))
			{
				sum+=x;
				x=0;
			}
			else
			{
				sum++;
				x=min((x+a)/2,(int)sqrt(x+b));
			}
		}
		cout<<sum<<endl;
	} 
	return 0;
}
