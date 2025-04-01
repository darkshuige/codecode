#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10005;
signed main()
{
	double sum=1;
	string s="";
	for(int i=0;i<3;i++)
	{
		int pos=0;
		double ma=-1;
		for(int k=0;k<3;k++)
		{
			double x; cin>>x;
			if(x>ma)
			{
				ma=x; pos=k;
			}
		}
		if(i!=0) s+=" ";
		if(pos==0)
		 s+="W";
		else if(pos==1)
		 s+="T";
		else
		 s+="L";
		sum*=ma;
	}
	cout<<s;
	sum*=0.65;
	sum-=1; sum*=2;
	cout<<" "<<fixed<<setprecision(2)<<sum<<endl;
	return 0;
} 