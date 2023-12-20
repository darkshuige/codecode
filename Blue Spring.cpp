#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=500005;
int a[maxn];
int cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	jiasu;
	memset(a,0,sizeof 0);
	int n,d,p;
	int sum=0;
	int ss=0;
	cin>>n>>d>>p;
	double ave=(double)(p)/(double)(d);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ss+=a[i];
		if(a[i]>ave)
		 sum++;
	}
	sort(a,a+n,cmp);
	int pos=0;
	int ans1=ss,ans2=ss;
	int num=sum/d;
	for(int i=0;i<num*d;i++)
	 ans1-=a[i];
	ans1+=num*p;
	num+=1;
	for(int i=0;i<num*d;i++)
	 ans2-=a[i];
	ans2+=num*p;
	cout<<min(ans1,ans2)<<endl;
	return 0;
}
