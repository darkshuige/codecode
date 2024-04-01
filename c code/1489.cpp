#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		set<int>sb;
		for(int j=0;j<k;j++)
		{
			int a;
			cin>>a;
			sb.insert(a);
		}
		cout<<sb.size()<<endl;
	}
	return 0;
} 
