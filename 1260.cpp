#include<bits/stdc++.h>
using namespace std;
bool a[10005];
int main()
{
	memset(a,1,sizeof a);
	int n,t;
	cin>>n>>t;
	int i;
	for(i=0;i<t;i++)
	{
		int l,r;
		cin>>l>>r;
		memset(a+l,0,r-l+1);
	}
	int count=0;
	for(i=0;i<=n;i++)
	{
		if(a[i])
		 count++;
	}
	cout<<count<<endl;
	return 0;
}
