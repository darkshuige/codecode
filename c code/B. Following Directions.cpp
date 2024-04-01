#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int x=0,y=0,flag=0;
		for(int j=0;j<n;j++)
		{
			char op;
			cin>>op;
			if(op=='U')
			 y++;
			else if(op=='L')
			 x--;
			else if(op=='D')
			 y--;
			else if(op=='R')
			 x++;
			if(x==1 && y==1)
			 flag=1;
		}
		if(flag==1)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
    return 0;
}
