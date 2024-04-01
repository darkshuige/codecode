#include<bits/stdc++.h>
using namespace std;
void f(int &a,int &b)
{
	a=0;
	if(b<100)
	{
		a=b;
	}
	else
	{
		int n,m;
		n=b%10;
		m=b/10%10;
		a=m*10+n;
	}
}
int main()
{
	int n;
	cin>>n;
	int a,b,c,d,ans,e;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		f(c,a);
		f(d,b);
		e=c+d;
		f(ans,e);
		cout<<ans<<endl;
	}
	return 0;
}
