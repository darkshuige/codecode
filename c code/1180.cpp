#include<iostream>
using namespace std;
int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int n,flag=0;
		cin>>n;
		int a[5000]={0};
		cin>>a[0];
		if(a[0]==0)
		 flag=1;
		n--;
		int m=1;
		int j,l;
		for(j=0;j<n;j++)
		{
			cin>>l;
			if(l==0)
			 flag=1;
			int k;
			for(k=0;k<m;k++)
			{
				a[k]*=l;	
			}	
			for(k=0;k<m-1;k++)
			{
				a[k+1]+=a[k]/10;
				a[k]%=10;
			}
			while(a[m-1]>10)
			{
				a[m]+=a[m-1]/10;
				a[m-1]%=10;
				m++;
			}
		}
		if(flag)
		 cout<<"0";
		else
		{
			for(int k=m-1;k>=0;k--)
			 cout<<a[k];
		}
		cout<<endl;
	}
	return 0;
} 
