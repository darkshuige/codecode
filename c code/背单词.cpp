#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cou.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int n,m;
	cin>>n>>m;
	int cnt=0;
	while(n>0)
	{
		cnt++;
		n-=m;
		if(m%2==0)
		 m/=2;
		else
		 m=m*3+1;
		if(m==1 || m==2 || m==4)
		{
			cnt+=(n/7)*3;
			n%=7;
		}
	}
	cout<<cnt<<endl;
    return 0;
}