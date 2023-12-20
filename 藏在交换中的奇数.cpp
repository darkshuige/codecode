#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int a[105];
		int flag=0;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			if(a[j]%2==1 && a[j]<a[0])
			 flag=1;
		}
		if(a[0]%2==1)
		 flag=-1;
		if(flag==1)
		 cout<<1<<endl;
		else if(flag==0)
		 cout<<-1<<endl;
		else if(flag==-1)
		 cout<<0<<endl;
	}
	return 0;
} 
