#include<bits/stdc++.h>
using namespace std;
int cmp(pair<string,int>a,pair<string,int>b)
{
	if(a.second!=b.second)
	{
		return a.second>b.second;
	}
	else
	{
		return a.first<b.first;
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		pair<string,int>a[110];
		for(int i=0;i<n;i++)
		{
			cin>>a[i].first>>a[i].second;
		}	
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		 cout<<a[i].first<<" "<<a[i].second<<endl;
	}
	return 0;
}
