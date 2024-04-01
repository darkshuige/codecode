#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		int sum=0;
		cin>>a>>b;
		for(int j=1;j<=a;j++)
		 if(j%b==0)
		  sum+=j;
		cout<<sum<<endl;
	}
}
