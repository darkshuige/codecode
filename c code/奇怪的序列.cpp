#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=1000005;
int a[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	int maxn=INT_MIN;
	for(int i=0;i<n-1;i++)
	{
		int cnt=1;
		for(int j=i+1;j<n;j++)
		{
			if((j-i)%2==1)
			{
				if(a[j]==a[i]+(j-i)/2+1)
				{
					cnt++;
					maxn=max(cnt,maxn);
				}
				else
				{
					break;	
				}
			}
			else
			{
				if(a[j]==a[i]-(j-i)/2)
				{
					cnt++;
					maxn=max(cnt,maxn);
				}
				else
				{
					break;	
				}
				 
			}
		}
	}
	cout<<maxn<<endl;
	return 0;
} 
