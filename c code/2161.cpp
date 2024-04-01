#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int h=0,f=0,s=0;
	s=t;
	f=s/60;
	s%=60;
	h=f/60;
	f%=60;
	printf("%d:%d:%d\n",h,f,s);
	return 0;
} 
