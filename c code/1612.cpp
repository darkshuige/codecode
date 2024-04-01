#include<bits/stdc++.h>
using namespace std;
int gys(int a,int b)
{
	int t;
	if(a<b)
	{
		t=a;a=b;b=t;
	}
	t=a%b;
	while(t)
	{
		a=b;
		b=t;
		t=a%b;
	}
	return b;
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<gys(a,b)<<endl;
	}
}
