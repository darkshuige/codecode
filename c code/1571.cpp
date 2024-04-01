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
		int a,b;
		cin>>a>>b;
		int g=gys(a,b);
		int flag=0;
		if(g==1)
		{
			cout<<n<<endl;
			flag=1;
		}
		for(int j=0;j<n-2;j++)
		{
			int op;
			cin>>op;
			g=gys(g,op);
			if(g==1 && flag==0)
			{
				cout<<n<<endl;
				flag=1;
			}
		}
		if(flag==0)
		 cout<<-1<<endl;
	}
	return 0;
} 
