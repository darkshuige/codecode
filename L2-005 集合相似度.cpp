#include<bits/stdc++.h>
using namespace std;
int main()
{
	set<int>a[55];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int j;
		cin>>j;
		for(int k=0;k<j;k++)
		{
			int as;
			cin>>as;
			a[i].insert(as);
		}
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int nt=0;
		int l,r;
		cin>>l>>r;
		set<int>::iterator it;
		for(it=a[l].begin();it!=a[l].end();it++)
		{
			if(a[r].count(*it))
			{
				nt++;
			}
		}
		printf("%.2f\%\n",(double)(nt)/(double)(a[l].size()+a[r].size()-nt)*100);
	}
	return 0;
} 
