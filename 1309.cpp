#include<bits/stdc++.h>
using namespace std;
int c1,c2,c3,c4;
int act1(int c[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	 sum+=min(c[i]*c1,c2);
	return sum;
}
int main()
{
	while(cin>>c1>>c2>>c3>>c4)
	{
		int n,m;
		int a[1005]={0},b[1005]={0};
		cin>>n>>m;
		for(int i=0;i<n;i++)
		 cin>>a[i];
		for(int i=0;i<m;i++)
		 cin>>b[i];
		int min1=INT_MAX,min2=INT_MAX;
		min1=min(min1,act1(a,n));
		min2=min(min2,act1(b,m));
		min1=min(min1,c3);
		min2=min(min2,c3);
		int minn;
		minn=min(min1+min2,c4);
		cout<<minn<<endl;
	}
	return 0;
} 
