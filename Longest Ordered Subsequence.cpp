#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include<string>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int a[maxn],f[maxn];
signed main()
{
	int n;
	while(cin>>n)
	{
		memset(f,0,sizeof f);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			f[i]=1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(a[i]>a[j])
				{
					f[i]=max(f[i],f[j]+1);
				}
			}
			ans=max(ans,f[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}