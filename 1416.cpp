#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int n;
	while(cin>>n)
	{
		char a[10],b[10];
		cin>>a;
		for(int i=1;i<n*2-1;i++)
		{
			cin>>b;
			for(int j=0;j<7;j++)
			{
				a[j]^=b[j];
			}
		}
		cout<<a<<endl;
	}
	return 0;
}
