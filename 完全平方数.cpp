#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		if(sqrt(op)==(int)sqrt(op))
		 sum++;
	} 
	cout<<sum<<endl;
	return 0;
}
