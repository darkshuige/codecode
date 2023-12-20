#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a[100005],b[100005];
int cmp(const long long a,const long long b)
{
	return a>b;
}
long long check(long long x)
{
	long long number=0;
	long long i=0,j=m-1;
	for(;i<n && j>=0;i++)
	{
		if(a[i]*b[j]>=x)
		{
			number+=j+1;
		}
		else
		{
			while(j>=0 && a[i]*b[j]<x)
			 j--;
			if(j>=0)
			 number+=j+1;
		}
	}
	return number;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		cin>>n>>m>>k;
		for(int j=0;j<n;j++)
		 cin>>a[j];
		for(int j=0;j<m;j++)
		 cin>>b[j];
		sort(a,a+n,cmp);
		sort(b,b+m,cmp);
		long long l=a[n-1]*b[m-1],r=a[0]*b[0];
		long long ans=0;
		while(l<=r)
		{
			long long mid=(l+r)>>1;
			if(check(mid)>=k)
			{
				l=mid+1;
				ans=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
