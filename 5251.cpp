#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int maxn=INT_MIN;
	map<double,int>sb;
	for(int i=0;i<n;i++)
	{
		double a;
		cin>>a;
		sb[a]++;
		if(sb[a]>maxn) maxn=sb[a];
	}
	map<double,int>::iterator it;
	for(it=sb.begin();it!=sb.end();it++)
	{
		if(it->second==maxn)
		 printf("%.2f\n",it->first);
	}
	return 0;
}
