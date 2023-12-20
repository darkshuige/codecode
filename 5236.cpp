#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string a;
		cin>>a;
		if(a.size()==1)
		 for(int j=0;j<6;j++)
		  cout<<a;
		else if(a.size()==2)
		 for(int j=0;j<3;j++)
		  cout<<a;
		else if(a.size()==3)
		 for(int j=0;j<2;j++)
		  cout<<a;
		cout<<endl;
	}
	return 0;
}
