#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a,b;
		cin>>a>>b;
		int sum=a+b;
		int c=1;
		while(c==sum)
		 c++;
		cout<<c<<endl;
	}
	return 0;	
}
