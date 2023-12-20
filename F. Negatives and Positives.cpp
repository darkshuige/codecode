#include<bits/stdc++.h>
using namespace std;
int cmp(const int a,const int b)
{
	return abs(a)<abs(b);
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int po=0,ne=0,ling=0;
		long long sum=0;
		int a[200005]={0};
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			sum+=abs(a[j]);
			if(a[j]==0)
			 ling++;
			if(a[j]>0)
			 po++;
			else if(a[j]<0)
			 ne++;
		}
		if(ne%2==0)
		 cout<<sum<<endl;
		else
		{
			sort(a,a+n,cmp);
			sum-=abs(a[0]*2);
			cout<<sum<<endl;
		}
	}
    return 0;
}
