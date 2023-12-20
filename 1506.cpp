#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a[110];
	double sum=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	double ave=sum/(double)(n);
	double sum2=0;
	for(int i=0;i<n;i++)
	 sum2+=pow((a[i]-ave),2);
	sum2/=(double)(n);
	printf("%.5f\n",sqrt(sum2));
	return 0;
} 
