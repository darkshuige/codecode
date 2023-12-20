#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[110]={0};
		int sum2=0,cnt=0;
		for(int i=0;i<n;i++)
		{
			int op;
			cin>>op;
			a[op]++;
		}
		for(int i=0;i<=100;i++)
		{
			if(a[i]!=0)
			{
				cnt++;
				sum2+=(a[i]-1);	
			}
		}
		int k;
		cin>>k;
		if(k<=sum2)
		 cout<<cnt<<endl;
		else if(k>sum2)
		{
			int jian=k-sum2;
			cout<<cnt-jian<<endl;
		}
	}
	return 0;
}
