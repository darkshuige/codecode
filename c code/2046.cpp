#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
    	int h=0,fz=0;
    	fz+=t/60;
    	t%=60;
    	h+=fz/60;
    	fz%=60;
    	printf("%d:%d:%d\n",h,fz,t);
	}
    return 0;
}
