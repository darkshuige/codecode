#include<iostream>
using namespace std;
int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int j,m;
		int a[55]={0},b[55]={0};
		cin>>m;
		for(j=0;j<m;j++)
		 cin>>a[j];
		for(j=0;j<m;j++)
		 cin>>b[j];
		for(j=0;j<m;j++)
		{
			if(a[j]*3<b[j])
			 break;
		}
		if(j!=m)
		 cout<<j+1<<endl;
		else
		 cout<<"-1"<<endl;
	}
	return 0;
}
