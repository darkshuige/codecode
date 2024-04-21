#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200;
double a[maxn];
int b[maxn];
signed main()
{
	jiasu;
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	int a1,b1;
	while(cin>>a1>>b1)
	{
		if(a1==0 && b1==0) break;
		b[a1]+=b1;
	}
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<endl;
		sum+=a[i]*b[i];
	}
	cout<<fixed<<setprecision(2)<<sum<<endl;
	return 0;
}