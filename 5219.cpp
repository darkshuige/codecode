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
		a[0]=toupper(a[0]);
		for(int j=1;j<a.size();j++)
		 a[j]=tolower(a[j]);
		cout<<a<<endl;
	}
	return 0;
}
