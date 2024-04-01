#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool a[7][7]={0};
	int a1,a2,a3,a4,a5,a6;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	a[1][a1]=1;a[2][a2]=1;a[3][a3]=1;a[4][a4]=1;a[5][a5]=1;a[6][a6]=1;
	int n;			
	cin>>n;  		
	int i;			
	int k=0;	
	for(i=6,k=0;k<n;i--,k++)
	{
		if(a[1][i]==true)
		 i--;
	}
	cout<<i+1;
	for(i=6,k=0;k<n;i--,k++)
	{
		if(a[2][i]==true)
		 i--;
	}
	cout<<" "<<i+1;
	for(i=6,k=0;k<n;i--,k++)
	{
		if(a[3][i]==true)
		 i--;
	}
	cout<<" "<<i+1;
	for(i=6,k=0;k<n;i--,k++)
	{
		if(a[4][i]==true)
		 i--;
	}
	cout<<" "<<i+1;
	for(i=6,k=0;k<n;i--,k++)
	{
		if(a[5][i]==true)
		 i--;
	}
	cout<<" "<<i+1;
	for(i=6,k=0;k<n;i--,k++)
	{
		if(a[6][i]==true)
		 i--;
	}
	cout<<" "<<i+1;
	return 0;
}
