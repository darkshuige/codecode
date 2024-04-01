#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,u,d;
		cin>>n>>u>>d;
		int sum=0;
		int count=0;
		while(1)
		{
			count++;
			sum+=u;
			if(sum>=n)
			 break;
			count++;
			sum-=d;
		}
		cout<<count<<endl;
	}
	return 0;
} 
