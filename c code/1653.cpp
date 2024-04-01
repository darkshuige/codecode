#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int sum=0;
		int ave=n/m;
		int a[110]={0};
		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			a[k]++;
		}
		for(int i=1;i<=m;i++)
		{
			if(a[i]>ave)
			 sum+=a[i]-ave;
		}
		cout<<sum<<endl;
	}
	return 0;
}
