#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;
int a[maxn];
int f(int a)
{
	return 2*(int)(abs(a*a*a-3*a)/(3*a*a+1));
}
signed main() 
{
	jiasu;
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
     cin>>a[i];
    while(q--)
    {
    	int op,l,r;
    	cin>>op>>l>>r;
    	if(op==1)
		 for(int i=l;i<=r;i++)
		  a[i]=f(a[i]);
		else
		{
			int sum=0;
			for(int i=l;i<=r;i++)
			 sum+=a[i];
			cout<<sum<<endl;
		}
	}
    return 0;
}