#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,m,x,y;
		cin>>n>>m>>x>>y;
		int count=4;
		if(x==1)
		 count--;
		if(y==1)
		 count--;
		if(x==n)
		 count--;
		if(y==m)
		 count--;
		cout<<count<<endl;
	}
	return 0;
}
