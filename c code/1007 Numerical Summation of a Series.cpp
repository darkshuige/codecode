#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1e6;
signed main()
{
	double ans=0;
	for(double i=20000.0;i<=maxn;i++)
	{
		ans+=1/((i+1)*i*i);
	}
	for(double x=0;x<=2.000;x+=0.001)
	{
		double res=ans;
		for(double k=1;k<=20000;k++)
		{
			res+=1/(k*(k+x)*(k+1));
		}
		res*=(1-x);
		res+=1;
		printf("%5.3f %16.12f\n",x,res);
	}
	return 0;
} 
