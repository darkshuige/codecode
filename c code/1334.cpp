#include<bits/stdc++.h>
using namespace std;
int a[200][200]={0};
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[j][i];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j!=0) cout<<" ";
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
