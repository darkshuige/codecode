#include<bits/stdc++.h>
using namespace std;
int gys(int a,int b)
{
	if(a<b)
	 swap(a,b);
	int t=a%b;
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
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b,d;
		cin>>a>>b>>d;
		if(d%gys(a,b)==0)
		 cout<<"Yes"<<endl;
		else
		 cout<<"No"<<endl;
	}
	return 0;
} 
