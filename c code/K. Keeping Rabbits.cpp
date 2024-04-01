#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100010;
int a[maxn];
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		double k;
		cin>>n>>k;
		double sum=k;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		double pp=sum-k;
		for(int i=0;i<n;i++)
		{
			if(i!=0)
			 cout<<" ";
			double op=sum*a[i]/pp;
			cout<<fixed<<setprecision(8)<<op;
		}	
		cout<<endl;
	}
	return 0;
} 
