#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=3000;
int f[maxn][maxn];
int t,maxp,w;
int ap,bp,as,bs;
deque<int>de;
signed main()
{
	jiasu;
	cin>>t>>maxp>>w;
	memset(f,-inf,sizeof f);
	for(int i=1;i<=t;i++)
	{
		cin>>ap>>bp>>as>>bs;
		for(int j=0;j<=as;j++) f[i][j]=-ap*j;//凭空买
		for(int j=0;j<=maxp;j++) f[i][j]=max(f[i][j],f[i-1][j]);//不买不卖
		if(i<=w) continue;
		de.clear();
		for(int j=0;j<=maxp;j++)
		{
			while(!de.empty() && f[i-w-1][de.back()]+ap*de.back()<=f[i-w-1][j]+ap*j) de.pop_back();
			de.push_back(j);		
			if(de.front()<j-as) de.pop_front();
			f[i][j]=max(f[i][j],f[i-w-1][de.front()]-ap*(j-de.front()));
		}
		de.clear();
		for(int j=maxp;j>=0;j--)
		{
			while(!de.empty() && f[i-w-1][de.back()]+bp*de.back()<=f[i-w-1][j]+bp*j) de.pop_back();
			de.push_back(j);
			if(de.front()>j+bs) de.pop_front();
			f[i][j]=max(f[i][j],f[i-w-1][de.front()]+bp*(de.front()-j));
		}
	}
	cout<<f[t][0]<<endl;
	return 0;
}