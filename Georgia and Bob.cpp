#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn];
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--)
		{
			b[n-i+1]=a[i]-a[i-1]-1;
		}
		int s=0;
		for(int i=1;i<=n;i++)
		 if(i%2==1)
		  s^=b[i];
		if(s)
		 cout<<"Georgia will win"<<endl;
		else
		 cout<<"Bob will win"<<endl;
	}
	return 0;
} 
