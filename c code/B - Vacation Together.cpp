#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int n,d;
	cin>>n>>d;
	char a[105][105];
	int k[105]={0};
	for(int i=0;i<n;i++)
	 cin>>a[i];
	int cnt=0;
	for(int i=0;i<d;i++)
	{
		int flag=1;
		for(int j=0;j<n;j++)
		{
			if(a[j][i]=='x')
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		 k[i]=1;
	}
	int sum=0;
	for(int i=0;i<d;i++)
	{
		if(k[i]==1)
		{
			sum++;
			cnt=max(sum,cnt);
		}
		else
		 sum=0;
	}
	cout<<cnt<<endl;
	return 0;
}
