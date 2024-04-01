#include<iostream>
using namespace std;
int main()
{
	int n,m,c,d;
	int i,a[100005]={0},b[100005]={0};
	cin>>n>>m;
	for(i=0;i<n;i++)
	 cin>>a[i];
	for(i=0;i<m;i++)
	{
		cin>>c>>d;
		b[c]=d;
	}
	for(i=0;i<n;i++)
	{
		d=a[i];
		while(b[d])
		{
			d=b[d];
		}
		if(i!=0)
		 cout<<" ";
		cout<<d;
	}
	return 0;
} 
