#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=20;
int n,m,prim[maxn];
int calc()
{
	int res=0;
	for(int i=1;i<(1<<m);i++)//枚举状态，有m个集合s，转换成二进制，有几个1就是几个集合交集
	{
		int t=1,sign=-1;
		for(int j=0;j<m;j++)//看每一次的状态
		{
			if(i & (1<<j))
			{
				if(t*prim[j]>n)
				{
					t=0;
					break;
				}
				t*=prim[j];//集合s交集后的个数除以n之前，除了n才是真个数。每个题算法不一样
				sign=-sign;//每多一个集合就要换一个状态
			}
			if(t) res+=n/t*sign;
		}
	}
	return res;
}
signed main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	 cin>>prim[i];
	cout<<calc()<<endl;
	return 0;
}