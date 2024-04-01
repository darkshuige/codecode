#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a==0 && b==0 && c==0)
		 break;
		double s[4]={0};
		s[0]=a*b/2,s[1]=(a-c)*a/2,s[2]=(a-b)*a/2,s[3]=a*c/2;
		sort(s,s+4);
		int i=0;
		while(s[i]==0)
		 i++;
		printf("%.1f\n",s[i]);
	}
	return 0;
}
