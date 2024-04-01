#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int maxn=INT_MIN;
		int minn=INT_MAX;
		for(int j=0;j<n;j++)
		{
			int a;
			cin>>a;
			if(a>maxn) maxn=a;
			if(a<minn) minn=a;
		}
		cout<<maxn-minn<<endl;
	}
	return 0;
} 
