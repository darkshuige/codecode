#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cou.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int n,m;
	cin>>n>>m;
	int sum=0,cnt=0;
	while(sum<n)
	{
		sum+=m;
		if(m%2==0)
		 m/=2;
		else
		 m=m*3+1;
		cnt++;
	}
	cout<<cnt<<endl;
    return 0;
}