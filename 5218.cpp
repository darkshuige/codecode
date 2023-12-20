#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long h,a,b;
		scanf("%lld%lld%lld",&h,&a,&b);
		if(a<=b && h>a)
		{
			cout<<-1<<endl;
			continue;
		}
		else if(a>=h)
		{
			cout<<1<<endl;
			continue;
		}
		else
		{
			h-=a;
        	printf("%lld\n",(h-1)/(a-b)+2);
		}
	}
	return 0;
}



