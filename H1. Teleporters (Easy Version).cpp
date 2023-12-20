#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,c;
		cin>>n>>c;
		int v[200005]={0};
		for(int j=1;j<=n;j++)
		{
			cin>>v[j];
			v[j]+=j;
		}
		sort(v+1,v+1+n);
		int k=1;
		while(c>=v[k] && k<=n)
		{
			c-=v[k];
			k++;
		}
		cout<<k-1<<endl;
	}
    return 0;
}
