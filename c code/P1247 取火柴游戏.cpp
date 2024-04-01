#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=500005;
int a[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s^=a[i];
	}
	if(s==0)
	 cout<<"lose"<<endl;
	else
	{
		for(int i=1;i<=n;i++)
		{
			if((s^a[i])<a[i])
			{
				cout<<(a[i]-(s^a[i]))<<" "<<i<<endl;
				a[i]=(s^a[i]);
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=1)
			 cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
} 
