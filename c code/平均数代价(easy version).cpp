#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
signed main()
{
	jiasu;
	int n,p,x,q,y;
	cin>>n>>p>>x>>q>>y;
	int sum=0;
	double ave;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		sum+=op;
	}
	ave=(double)sum/(double)n;
	if(ave==(int)ave)
	 cout<<0<<endl;
	else
	{
		int minn=(((sum/n+1)*n)-sum)*p;
		int cost=0;
		while(1)
		{
			if(sum-y>=n)
			{
				sum-=y;
				cost+=q;
				int money;
				if(sum%n!=0)
				 money=cost+(((sum/n+1)*n)-sum)*p;
				else
				 money=cost;
				if(money<minn)
				 minn=money;
			}
			else
			 break;
		}
		cout<<minn<<endl;
	}
	return 0;
} 
