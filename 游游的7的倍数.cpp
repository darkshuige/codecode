#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
signed main()
{
	jiasu;
	int x;
	cin>>x;
	for(int i=0;i<=9;i++)
	{
		if(((x*10+i)%7)==0)
		{
			cout<<(x*10+i)<<endl;
			 return 0;	
		}
	}
	return 0;
} 
