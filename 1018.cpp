#include<iostream>
using namespace std;
int main()
{
	int i,n,m=1,sum=0,j,max,t,s;
	int a[10005]={0},b[10005]={0}; 
	cin>>n;
	while(n!=0)
	{
		s=0;
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
		}	
		for(i=0;i<n-1;i++)
		{
			max=i;
			for(j=i+1;j<n;j++)
			{
				if(b[j]>b[max])
				{
					max=j;
				}
			}
			t=b[i];
			b[i]=b[max];
			b[max]=t;
			t=a[i];
			a[i]=a[max];
			a[max]=t;
		}
		max=0;
		for(i=0;i<n;i++)
		{
			sum+=a[i];	
			s=sum+b[i];
			if(s>max)
			 max=s;
		}
		sum=s;
		if(max<sum)
		 cout<<"Case "<<m<<": "<<sum<<endl;
		else
		 cout<<"Case "<<m<<": "<<max<<endl;
		m++;
		cin>>n;
	}
	
	return 0;
}
