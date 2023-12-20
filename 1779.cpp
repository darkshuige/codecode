#include<bits/stdc++.h>
using namespace std;
long long b[50000];
int main()
{
	int t;
	int count=1;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		memset(b,0,sizeof b);
		map<long long,long long>a; 
		int n;
		cin>>n;
		int k=0;
		for(int i=0;i<n;i++)
		{
			long long op;
			cin>>op;
			if(a[op]==0)
			{
				a[op]=1;
				b[k++]=op;
			}
		}
		printf("Case #%d: ",count);
		count++;
		for(int i=0;i<k;i++)
		{
			if(i!=0)
			 cout<<" ";
			cout<<b[i];
		}
		cout<<endl;	
	}
	return 0;
}
