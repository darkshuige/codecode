#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
struct node
{
	int x1,x2,y1,y2,z1,z2;
}a[maxn];
int cnt[maxn]={0};
int check(int z11,int z12,int z21,int z22)
{
	if(((z21>=z11 && z21<z12) || (z22<=z12 && z22>z11)) || ((z11>=z21 && z11<z22) || (z12<=z22 && z12>z21)))
	 return 1;
	return 0;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x1>>a[i].y1>>a[i].z1>>a[i].x2>>a[i].y2>>a[i].z2;
		for(int j=1;j<=i-1;j++)
		{
			if((a[j].x1==a[i].x2 && check(a[i].z1,a[i].z2,a[j].z1,a[j].z2) && check(a[i].y1,a[i].y2,a[j].y1,a[j].y2)) || (a[j].x2==a[i].x1 && check(a[i].z1,a[i].z2,a[j].z1,a[j].z2) && check(a[i].y1,a[i].y2,a[j].y1,a[j].y2)))
			 cnt[i]++,cnt[j]++;
			else if((a[j].y1==a[i].y2 && check(a[i].z1,a[i].z2,a[j].z1,a[j].z2) && check(a[i].x1,a[i].x2,a[j].x1,a[j].x2)) || (a[j].y2==a[i].y1 && check(a[i].z1,a[i].z2,a[j].z1,a[j].z2) && check(a[i].x1,a[i].x2,a[j].x1,a[j].x2)))
			 cnt[i]++,cnt[j]++;
			else if((a[j].z1==a[i].z2 && check(a[i].x1,a[i].x2,a[j].x1,a[j].x2) && check(a[i].y1,a[i].y2,a[j].y1,a[j].y2)) || (a[j].z2==a[i].z1 && check(a[i].x1,a[i].x2,a[j].x1,a[j].x2) && check(a[i].y1,a[i].y2,a[j].y1,a[j].y2)))
			 cnt[i]++,cnt[j]++;
		}
	}
	for(int i=1;i<=n;i++)
	 cout<<cnt[i]<<endl;
	return 0;
} 
