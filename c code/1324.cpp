#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;
	while(cin>>n>>x)
	{
		if(n==0 && x==0)
		 break;
		vector<int>sb;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			sb.push_back(a);
		}
		vector<int>::iterator it;
		for(it=sb.begin();it!=sb.end();it++)
		{
			if(*it>x)
			 break;
		}
		sb.insert(it,x);
		int count=0;
		for(it=sb.begin();it!=sb.end();it++)
		{
			if(count!=0)
			 cout<<" ";
			cout<<*it;
			count++;
		}
		cout<<endl;
	}
	return 0;
}
