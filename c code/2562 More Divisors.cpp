#include<bits/stdc++.h>
#define int long long
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
using namespace std;
const int maxn=1010;
int f(int i)
{
	int sum=0;
	for(int j=1;j<i/2;j++)
	{
		if(i%j==0)
		 sum+=2;
	}
	return sum;
}
signed main()
{
	int n;
	while(cin>>n)
	{
		int maxn=0;
		int pos=n/2;
		for(int i=n/2;i<=n;i++)
		{
			int s=f(i);
			if(s>maxn)
			{
				maxn=s;
				pos=i;
			}
		}
		cout<<pos<<endl;
	}
	return 0;
} 

