#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		m+=30;
		int count=0;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			if(a<=m)
			 count++;
		}
		cout<<n-count<<endl;
	}
 } 
