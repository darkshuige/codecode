#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int maxn=INT_MIN;
		int minn=INT_MAX;
		int i;
		for(i=0;i<n;i++)
		{
			int a;
			cin>>a;
			if(a>maxn) maxn=a;
			if(a<minn) minn=a;
		}
		cout<<maxn<<" "<<minn<<endl;
	}
	return 0;
} 
