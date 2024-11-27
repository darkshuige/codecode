#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int a[maxn];
int isp(int n)
{
	if(n<2) return 0;
	for(int i=2;i<=sqrt(n);i++)
	 if(n%i==0) return 0;
	return 1;
}
signed main()
{
	jiasu;
	int n,d;
	while(cin>>n)
	{
		if(n<0) break;
		cin>>d;
		if(isp(n)==0)
		 cout<<"No"<<endl;
		else
		{
			int cnt=0;
			while(n)
			{
				a[cnt++]=n%d;
				n/=d;
			}
			int now=0; cnt--; int sum=0;
			for(cnt;cnt>=0;cnt--)
			{
				sum+=pow(d,now)*a[cnt];
				now++;
			}
			if(isp(sum))
			 cout<<"Yes"<<endl;
			else
			 cout<<"No"<<endl;
		}
	}
	return 0;
} 