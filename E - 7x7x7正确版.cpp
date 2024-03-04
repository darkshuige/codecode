#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
int f1(int x1,int y1,int z1,int x2,int y2,int z2)
{
	int res=1;
	res*=max(0,min(x1,x2)+7-max(x1,x2));
	res*=max(0,min(y1,y2)+7-max(y1,y2));
	res*=max(0,min(z1,z2)+7-max(z1,z2));
	return res;
}
int f2(int x1,int y1,int z1,int x2,int y2,int z2,int x3,int y3,int z3)
{
	int res=1;
	res*=max(0,min({x1,x2,x3})+7-max({x1,x2,x3}));
	res*=max(0,min({y1,y2,y3})+7-max({y1,y2,y3}));
	res*=max(0,min({z1,z2,z3})+7-max({z1,z2,z3}));
	return res;
}
signed main()
{
	jiasu;
	int v1,v2,v3;
	cin>>v1>>v2>>v3;
	int x1=0,y1=0,z1=0,x2,y2,z2,x3,y3,z3;
	for(x2=-7;x2<=7;x2++)
	{
		for(y2=-7;y2<=7;y2++)
		{
			for(z2=-7;z2<=7;z2++)
			{
				for(x3=-7;x3<=7;x3++)
				{
					for(y3=-7;y3<=7;y3++)
					{
						for(z3=-7;z3<=7;z3++)
						{
							int vv3=f2(x1,y1,z1,x2,y2,z2,x3,y3,z3);
							int vv2=f1(x1,y1,z1,x2,y2,z2)+f1(x1,y1,z1,x3,y3,z3)+f1(x3,y3,z3,x2,y2,z2)-3*vv3;
							int vv1=7*7*7*3-vv2*2-vv3*3;
							if(vv1==v1 && vv2==v2 && vv3==v3)
							{
								cout<<"Yes"<<endl;
								cout<<x1<<" "<<y1<<" "<<z1<<" "<<x2<<" "<<y2<<" "<<z2<<" "<<x3<<" "<<y3<<" "<<z3<<endl;
								return 0;
							}
						}
					}	
				}
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
