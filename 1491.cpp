#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		memset(a,0,sizeof a);
		int maxn=1;
		int t;
		cin>>t;
		int count=1;
		cin>>a[0];
		for(int j=1;j<t;j++)
		{
			cin>>a[j];
			if(a[j]==a[j-1]+1)
			{
				count++;	
				if(count>maxn)
				 maxn=count;
			}
			else
			{
				count=1;	
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
} 
