#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int i;
		int a[2]={0};
		char b[100005];
		cin>>b[0];
		for(i=1;i<n;i++)
		{
			cin>>b[i];
			if(b[i-1]=='D' && b[i]=='U')
			 a[0]++;
			if(b[i-1]=='U' && b[i]=='D')
			 a[1]++;
		}
		if(b[i-1]=='U')
		{
			a[1]++;
		}
		else
		{
			a[0]++;
		}
		int minx=min(a[0],a[1]);
		cout<<minx<<endl;
	}
	return 0;
}
