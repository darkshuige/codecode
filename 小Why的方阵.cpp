#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin,tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int a[3][3]={0};
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			for(int k=0;k<=9;k++)
			{
				int op=a[i][j];
				a[i][j]=k;
				if(a[1][1]+a[1][2]==a[2][1]+a[2][2] && a[1][1]+a[1][2]==a[1][1]+a[2][1] && a[1][1]+a[2][1]==a[1][2]+a[2][2])
				{
					cout<<"YES"<<endl;
					return 0;
				}
				a[i][j]=op;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
