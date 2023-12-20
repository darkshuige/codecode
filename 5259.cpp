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
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		if(n<=2)
		{
			cout<<1<<endl;
			continue;		
		}		
		int fz=2*n,fm=pow(2,n);
		int g=gys(fz,fm);
		fz/=g,fm/=g;
		printf("%d/%d\n",fz,fm);		
	}	 
	return 0;
}
