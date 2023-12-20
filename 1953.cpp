#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		int count=0;
		for(int i=0;i<a.size()-b.size()+1;i++)
		{
			string cp(a,i,b.size());
			if(cp==b)
			 count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
