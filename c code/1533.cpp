#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r;
	cin>>r;
	for(int i=0;i<r;i++)
	{
		int n;
		cin>>n;
		double sum=0;
		for(int j=1;j<=n;j++)
		{
			sum+=1.0/j;
		}
		printf("%.3f\n",sum);
	}
	return 0;
}
