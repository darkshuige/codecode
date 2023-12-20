#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int maxn=100005;
int a[maxn],b[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	n--;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int i=1;i<=n;i++)
	 cin>>b[i];
	int sum=a[1],pos=1;
	for(int i=2;i<=n;i++)
	{
		if(i==n)
		{
			if(b[i]>b[pos])
			{
				sum+=a[i];
				continue;
			}
		}
		if(b[i]>b[pos])
		{
			if(b[i+1]>b[i])
			{
				sum+=a[i+1];
				pos=i+1;
			}
			else if(b[i+1]<b[i])
			{
				sum+=a[i];
				pos=i;
			}
			else if(b[i+1]==b[i])
			{
				if(a[i]<a[i+1])
				{
					pos=i;
					sum+=a[i];
				}
				else
				{
					pos=i+1;
					sum+=a[i+1];
				}
			}
			i++;
		}
	}
	cout<<sum<<endl;
	return 0;	
} 
