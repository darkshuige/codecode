#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn];
int cmp(int a,int b)
{
	return a>b;	
}
signed main()
{
	jiasu;
	int n,m;
	cin>>n;
	double ans=1;
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++)
	{
		int op;
		double x;
		cin>>op>>x;
		if(op==1) a[cnt1++]=x;
		else b[cnt2++]=x;;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int op;
		double x;
		cin>>op>>x;
		if(op==2) a[cnt1++]=x;
		else b[cnt2++]=x;;
	}
	sort(a,a+cnt1,cmp);sort(b,b+cnt2,cmp);
	int p1=0,p2=0;
	while(p1<cnt1 && p2<cnt2)
	{
		if(ans<1)
		 ans*=a[p1++];
		else
		 ans/=b[p2++];
	}
	if(p1>=cnt1 && ans<1)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	if(p2>=cnt2 && ans>1)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	while(p1<cnt1)
	{
		ans*=a[p1++];
		if(p2>=cnt2 && ans>1)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	} 
	while(p2<cnt2)
	{
		ans/=b[p2++];	
		if(p1>=cnt1 && ans<1)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	} 
	if(abs(ans-1)<=1e-8)
	 cout<<"YES"<<endl;
	else
	 cout<<"NO"<<endl;
	return 0;
} 
