#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string a,b;
		cin>>a>>b;
		if(a.size()==b.size())
		 cout<<a<<" is equal long to "<<b<<endl;
		else if(a.size()>b.size())
		 cout<<a<<" is longer than "<<b<<endl;
		else
		 cout<<a<<" is shorter than "<<b<<endl;
	}
	return 0;
}
