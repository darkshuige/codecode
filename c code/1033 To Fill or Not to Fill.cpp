#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=505;
struct node
{
	double price,dis;
}a[maxn];
int cmp(node a,node b)
{
	return a.dis<b.dis;
}
double c,d,av;
int n;
signed main()
{
	cin>>c>>d>>av>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i].price>>a[i].dis;
	a[n].price=0; a[n].dis=d;
	int now=0;
	sort(a,a+n,cmp);
	if(a[0].dis!=0)
	{
		cout<<"The maximum travel distance = 0.00"<<endl;
		return 0;
	}
	double rest=0;
	double ma=av*c;
	double sum=0;
	while(now<n)
	{
		int pos=-1;
		double mi=100000000;
		for(int i=now+1;i<=n;i++)
		{
			if(a[i].dis<=ma+a[now].dis)
			{
				if(a[i].price<mi)
				{
					mi=a[i].price;
					pos=i;
					if(mi<a[now].price) break;
				}
			}
		}
		if(pos==-1) break;
		double need=(a[pos].dis-a[now].dis)/av;
		if(a[pos].price<=a[now].price)
		{
			if(rest>=need)
			{
				rest-=need;
				now=pos;
			}
			else
			{
				sum+=((need-rest)*a[now].price);
				rest=0;
				now=pos;
			}	
		}
		else
		{
			sum+=((c-rest)*a[now].price);
			rest=c-need;
			now=pos;
		}
	}
	if(now==n) cout<<fixed<<setprecision(2)<<sum<<endl;
	else cout<<"The maximum travel distance = "<<fixed<<setprecision(2)<<a[now].dis+c*av<<endl;
	return 0;
} 
