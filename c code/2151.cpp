#include<bits/stdc++.h>
using namespace std;
long long a[35],b[35];
void init()
{
	a[0]=1,a[1]=1;
	for(int i=2;i<35;i++) 
	 a[i]=a[i-2]+a[i-1];
	b[0]=0;
	for(int i=1;i<35;i++)
	 b[i]=a[i-1]+b[i-1];
}
int main()
{
	init();
	int l,r;
	while(cin>>l>>r)
	 cout<<b[r+1]-b[l]<<endl;
	return 0;	
}
