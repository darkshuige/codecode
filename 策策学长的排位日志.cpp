#include<bits/stdc++.h>
using namespace std;
struct person
{
	int k,d,a;
	double kda;
};
int main()
{
	int n,p,q;
	cin>>n>>p>>q;
	int flag=0;
	int fenshu=0;
	for(int i=0;i<n;i++)
	{
		person a[10];
		int sum1=0,sum2=0;
		for(int j=0;j<5;j++)
		{
			cin>>a[j].k>>a[j].d>>a[j].a;
			sum1+=a[j].k;
			sum2+=a[j].d;
			if(a[j].d!=0)
			 a[j].kda=(double)(a[j].k+a[j].a)/(double)a[j].d;
			else
			 a[j].kda=1000000;
		}
		if(sum1>=sum2)
		{
			fenshu+=p;
			if(a[0].kda>=a[1].kda && a[0].kda>=a[2].kda && a[0].kda>=a[3].kda && a[0].kda>=a[4].kda)
			 fenshu+=p;
		}
		else
		{
			if(a[0].kda>=a[1].kda && a[0].kda>=a[2].kda && a[0].kda>=a[3].kda && a[0].kda>=a[4].kda)
			 fenshu=fenshu;
			else
			{
				if(fenshu-q<0)
		 		 fenshu=0;
		 		else
		 		 fenshu-=q;
			}
		}
		if(fenshu>=100)
		 flag=1;
	}
	if(flag==1)
	 cout<<"YES"<<endl;
	else
	 cout<<"NO"<<endl;
    return 0;
}
