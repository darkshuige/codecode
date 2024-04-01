#include<bits/stdc++.h>
using namespace std;
int cmp(string a,string b)
{
	if(a.size()!=b.size())
	 return a.size()<b.size();
	else
	 return a<b;
}
int main()
{
	int n;
	while(cin>>n)
	{
		string a[110];
		for(int i=0;i<n;i++)
		 cin>>a[i];
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		 cout<<a[i]<<endl;
	}
	return 0;
}
