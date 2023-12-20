#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int n,k;
	cin>>n>>k;
	if(k*3>n)
	 cout<<-1<<endl;
	else
	{
		for(int i=0;i<k;i++)
		 cout<<"you";
		for(int i=0;i<n-k*3;i++)
		 cout<<"u";
	}
	cout<<endl;
	return 0;
}
