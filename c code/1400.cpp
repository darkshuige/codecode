#include<bits/stdc++.h>
using namespace std;
int f[3000001];
int main()
{
	int n;
	double q;
	while(cin>>q>>n)
	{
		memset(f,0,sizeof f);
		if(n==0)
		 break;
		int a[110]={0};
		int kk=0;
		for(int i=0;i<n;i++)
		{
			int m;
			cin>>m;
			int flag=1;
			long long sum=0;
			int r=0,t=0,y=0;
			for(int j=0;j<m;j++)
			{
				char op;
				double price;
				scanf(" %c:%lf",&op,&price);
				int g=(int)(price*100);
				if(op=='A'&& r+g<=60000)
		        {
		                r+=g;
		        }
		        else if(op=='B'&& t+g<=60000)
		        {
		                t+=g;
		        }
		        else if(op=='C'&& y+g<=60000)
		        {
		                y+=g;
		        }
		        else
		        {
		            flag=0;
		        }
		    }
	        if(r+t+y<=100000 && flag)
	        {
	            a[kk++]=r+t+y;
	        }
		}
		int w=(int)(q*100);
		for(int i=0;i<kk;i++)
		{
			for(int j=w;j>=a[i];j--)
			{
				f[j]=max(f[j],f[j-a[i]]+a[i]);
			}
		}
		double Q=f[w]*1.0/100;
		printf("%.2f\n",Q);
	}
	return 0;
} 
