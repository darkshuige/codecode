#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		int count=0;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			int a,b;
			cin>>a>>b;
			if(b-a>=2)
			 count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
