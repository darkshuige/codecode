#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
struct ps
{
	int x,y,cha;
}p[100005];
int cmp(ps a,ps b)
{
	return a.cha>b.cha;
};
signed main()
{
	jiasu;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	 cin>>p[i].x;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].y;
		p[i].cha=p[i].x-p[i].y;	
	}
	sort(p,p+n,cmp);
	int sum=0;
	for(int i=0;i<k;i++)
	 sum+=p[i].x;
	for(int i=k;i<n;i++)
	 sum+=p[i].y;
	cout<<sum<<endl;
	return 0;
} 
