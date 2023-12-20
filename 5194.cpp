#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n,b;
	while(cin>>n>>b)
	{
		if(n==0 && b==0)
		 break;
		int cnt=0;
		double o=b/2;
		double r=b/2;
		for(int i=0;i<n;i++)
		{
			double x,y;
			cin>>x>>y;
			if(r*r==y*y+(x-o)*(x-o))
			 cnt++;
		}
		cout<<cnt<<endl;
	}
    return 0;
}
