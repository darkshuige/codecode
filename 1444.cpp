#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(abs(a-b)<abs(a-c))
		 cout<<'A'<<endl;
		else
		 cout<<'B'<<endl;
	}
	return 0;
}
