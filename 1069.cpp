#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		double a[3]={0};
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[0]+a[1]>a[2])
		{
			double s=(a[0]+a[1]+a[2])/2;
			double aere=sqrt(s*(s-a[0])*(s-a[1])*(s-a[2]));
			printf("area=%.2f; perimeter=%.2f\n",aere,a[1]+a[2]+a[0]);
		}
		else
		 cout<<"These sides do not correspond to a valid triangle"<<endl;
	}
	return 0;
} 
