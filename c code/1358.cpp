#include<bits/stdc++.h>
using namespace std;
double f(int a)
{
	double sum=0;
	int i;
	for(i=1;i<=a;i++)
	{
		sum+=i;
	}
	return sum;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		 break;
		double sum=0;
		int i;
		for(i=1;i<=n;i++)
		{
			sum+=1.0/f(i);
		}
		printf("%.3f\n",sum);
	}
	return 0;
}
