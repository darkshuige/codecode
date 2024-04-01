#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	while(cin>>n>>m>>k)
	{
		vector<int>v;
		for(int i=1;i<=n;i++)
		 v.push_back(i);
		v.erase(v.begin()+m-1);
		int p=m-1;
		int n1=n-1;
		while(n1>1)
		{
			p--;
			p=(p+k)%n1;
			v.erase(v.begin()+p);
			n1--;
		}
		cout<<v[0]<<endl;
	}
	return 0;
} 
