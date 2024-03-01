#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200005;

int a[maxn];
int cmp(int a,int b)
{
	return a<b;
}
signed main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	for(int i=0;i<n;i++)
    	 cin>>a[i];
    	sort(a,a+n,cmp);
    	int sum=0;
    	sum+=a[0]*2*(n-1);
    	int s=0;
    	for(int i=1;i<=n-1;i++)
    	{
    		if(a[i]<a[0]*2)
    		 sum+=a[i]*2*(n-i-1);
    		else
    		 sum+=(a[0]*2*2)*(n-i-1);
		}
    	sum*=2;
    	cout<<sum<<endl;
	}
    return 0;
}
