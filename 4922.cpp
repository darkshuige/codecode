#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a[1005],s;
	while(cin>>s)
	{
		a[0]=s;
		for(int i=1;i<s.size();i++)
		{
			string cp(s,i);
			a[i]=cp;
		}
		sort(a,a+s.size());
		for(int i=0;i<s.size();i++)
		 cout<<a[i]<<endl;
	}
	return 0;
}
