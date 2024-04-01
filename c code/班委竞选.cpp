#include<iostream>
using namespace std;
int main()
{
	int a,b;
	int n,i,m,count=0;
	int max1[13]={0},max2[13]={0};
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;	
		if(b>max1[a])
		{
			max1[a]=b;
			max2[a]=i;
		}
	}
	for(i=1;i<=m;i++)
	{
		if(count!=0)
		{
			cout<<" ";
		}
		cout<<max2[i];
		count++;	
	}
	 
	return 0;
} 
