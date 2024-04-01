#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	long long sum=n*m;
	int count1=0,count2=0;
	set<int>hang,lie;
	for(int i=0;i<q;i++)
	{
		int op,k;
		cin>>op>>k;
		if(op==0)
		{
			if(hang.count(k))
			{
			}
			else
			{
				count1++;
				sum-=(m-count2);
				hang.insert(k);
			}
		}
		if(op==1)
		{
			if(lie.count(k))
			{
			}
			else
			{
				count2++;
				sum-=(n-count1);
				lie.insert(k);
			}
		}
	}
	cout<<sum<<endl;
	return 0;
} 
