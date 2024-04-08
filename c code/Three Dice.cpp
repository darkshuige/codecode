#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200;
int a1=0,b1=0;
void check(int i)
{
	if(i==1 || i==4)
	 a1+=i;
	else
	 b1+=i;
}
signed main()
{
	jiasu;
	int a,b; cin>>a>>b;
	int flag=0;
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			for(int k=1;k<=6;k++)
			{
				a1=0,b1=0;
				check(i);check(j);check(k);
				if(a1==a && b1==b)
				 flag=1;
			}
		}
	}
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}