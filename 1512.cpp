#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		double a,b,c;
		cin>>a>>b>>c;
		printf("%.2f\n",a*b*c/100);
	}
	return 0;
}
