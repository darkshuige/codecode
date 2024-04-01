#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200005;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int m,a;
		cin>>m>>a;
		double n=0;
		double sum=0;
		for(int i=m-a;i>=1;i--)
		{
			if(i%a==0 || a%i==0)
			{
				sum+=i;
				n++;
			}
		}
		if(sum/n>a)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
} 
