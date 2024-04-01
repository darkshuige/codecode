#include<bits/stdc++.h>
using namespace std;
int op[1000005]={0};
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int i;
	for(i=0;i<b.size();i++)
	{
		op[(int)(b[i])]++;
	}
	for(i=0;i<a.size();i++)
	{
		if(op[(int)(a[i])]==0)
		 cout<<a[i];
	}
	cout<<endl;
	return 0;
}
