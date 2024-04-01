#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int a[10];
	for(int i=1;i<=8;i++)
	 cin>>a[i];
	int sum=0;
	for(int i=1;i<=8;i++)
	{
		if(a[i]>=3)
		{
			a[i+1]+=a[i]/3;
			if(a[i]==5)
			 sum+=i*4;
			else
			 sum+=i*a[i];
		}
	}
	cout<<sum<<endl;
	return 0;
}
// 3 3
// 4 4
// 5 4
// 6 3 3
// 7 3 4
// 8 4 4
//  9 3 3 3
// 10 3 3 4
// 11 3 4 4
// 12 3 3 3 3
// 13 3 3 3 4
// 14 3 3 4 4
// 15 3 3 3 3 3
// 16 3 3 3 3 4
// 17 3 3 3 4 4
// 18 3 3 3 3 3 3
