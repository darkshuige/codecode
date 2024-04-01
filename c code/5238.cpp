#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		string a;
		cin>>n;
		cin>>a;
		a.erase(a.size()-1,1);
		a.insert(0,1,'0');
		cout<<a<<endl;
	}
	return 0;
} 
