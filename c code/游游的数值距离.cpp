#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
int f(int x)
{
	int ans=1;
	for(int i=1;i<=x;i++)
	 ans*=i;
	return ans;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	if(n<=2)
	{
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	int minn=INT_MAX;
	int aa=0,bb=0;
	for(int a=3;a<=13;a++)
	{
		int sum=f(a)-1;
		int l=1,r=200000000;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(abs(sum*mid-n)<minn && mid!=2)
			{
				minn=abs(sum*mid-n);
				aa=a;
				bb=mid;
			}
			if(sum*mid>n)
			 r=mid-1;
			else if(sum*mid<n)
			 l=mid+1;
			else
			 break;
		}
	}
	cout<<aa<<" "<<bb<<endl;
	return 0;
}
