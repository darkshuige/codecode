#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		double sum=0;
		for(int i=0;i<n;i++)
		{
			double a;
			cin>>a;
			sum+=a;
		}
		printf("%.2f\n",sum/(double)(n));
	}
	
	return 0;
} 
