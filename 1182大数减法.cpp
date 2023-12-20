#include<bits/stdc++.h>
using namespace std;
int c[10005],a[10005],b[10005];
int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int flag=0;
		string a1,b1;
		cin>>a1>>b1;
		if(a1==b1)
		{
			cout<<"0"<<endl;
			continue;
		}
		if(a1.size()<b1.size())
		{
			swap(a1,b1);
			 flag=1;	
		}
		else if(a1.size()==b1.size())
		{
			if(a1<b1)
			{
				swap(a1,b1);
				flag=1;
			}
		}
		
		for(int j=0;j<a1.size();j++)
		{
			a[j]=a1[j]-'0';
		}
		for(int j=0;j<b1.size();j++)
		{
			b[j]=b1[j]-'0';
		}
		if(a1.size()>b1.size())
		{
			int j,k,l=0;
			for(j=a1.size()-1,k=b1.size()-1;k>=0;j--,k--)
			{
				if(a[j]<b[k])
				{
					a[j]+=10;
					a[j-1]-=1;
					c[l]=a[j]-b[k];
				}
				else
				{
					c[l]=a[j]-b[k];
				}
				l++;
			}
			for(j;j>=0;j--)
			{
				c[l]=a[j];
				l++;
			}	
			for(j=0;j<l;j++)
			{
				if(c[j]<0)
				{
					c[j]+=10;
					c[j+1]--;
				}
			}
			while(c[l-1]<=0)
			 l--;
			if(flag)
			 cout<<"-";
			for(j=l-1;j>=0;j--)
			{
				cout<<c[j];
			}
			cout<<endl;
		}
		
		
		else if(a1.size()==b1.size())
		{
			
			int j,k,l=0;
			for(j=a1.size()-1,k=b1.size()-1;k>=0;j--,k--)
			{
				if(a[j]<b[k])
				{
					a[j]+=10;
					a[j-1]-=1;
					c[l]=a[j]-b[k];
				}
				else
				{
					c[l]=a[j]-b[k];
				}
				l++;
			}
			while(c[l-1]<=0)
			 l--;
			if(flag)
			 cout<<"-";
			for(j=l-1;j>=0;j--)
			{
				cout<<c[j];
			}
			cout<<endl;
		}
	}
	return 0;	
}
