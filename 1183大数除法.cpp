#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long b;
	char a[10005];
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>a>>b;
		long long j,y=0;
		for(j=0;j<strlen(a);j++)
		{
			y=y*10+(a[j]-'0');
			y%=b;
		}	
		cout<<y<<endl;
	}	
	return 0;
} 
