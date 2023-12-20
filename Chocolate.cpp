#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	if(n==1 && m==1)
	 cout<<"Walk Alone"<<endl;
	else if(n==1 || m==1)
	 cout<<"Kelin"<<endl;
	else
	{
		if((n+m-4)%2==0)
		 cout<<"Kelin"<<endl;
		else
		 cout<<"Walk Alone"<<endl;
	}	
	return 0;
} 
