#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i,n,j,k,flag=0;
	int x,y;
	string b;
	cin>>n;
	for(i=0;i<n;i++)
	{
		flag=0;
		x=0,y=0;
		cin>>k;
		cin>>b;
		for(j=0;j<k;j++)
		{
			if(b[j]=='L')
			 x--;
			if(b[j]=='R')
			 x++;
			if(b[j]=='U')
			 y++;
			if(b[j]=='D')
			 y--;
			if(x==1 && y==1)
			{
				cout<<"YES"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
		 cout<<"NO"<<endl;
	}
	return 0;
}
