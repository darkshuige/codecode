#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		if(op%2==0)
		 sum1++;
		else
		 sum2++;
	}
	if(abs(sum1-sum2)<=1)
	 cout<<"Good"<<endl;
	else
	 cout<<"Not Good"<<endl;
	return 0;
}
