#include<bits/stdc++.h>
using namespace std;
int main()
{
	double s,m,n,a;
	while(~scanf("%lf%lf",&m,&n))
	{
		a=m-28*n;
		s=a/m*100.0;
		printf("%.2f%%\n",s);
	}
	return 0;
}
