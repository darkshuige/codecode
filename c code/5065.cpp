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
		double l=50,r=50;
		double sum1=0,sum2=0;
		for(int j=0;j<n;j++)
		{
			char op;
			cin>>op;
			sum1+=l*0.5;
			l/=2;
			sum2+=r*0.5;
			r/=2;
			if(op=='H')
			 l+=50;
			else
			 r+=50;
		}
		if(sum1>sum2)
		 cout<<"H"<<endl;
		else if(sum1<sum2)
		 cout<<"M"<<endl;
		else if(sum1==sum2)
		 cout<<"HM"<<endl;
	}
	return 0;	
}
