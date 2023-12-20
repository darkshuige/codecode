#include<bits/stdc++.h>
using namespace std;
int cmp(string a,string b)
{
	return a.size()<b.size();
}
int main()
{
	int n;
	while(cin>>n)
	{
		getchar();
		string a[n];
		for(int i=0;i<n;i++)
		{
			getline(cin,a[i]);
			if(a[i]=="stop")
			{
				n=i;
				break;
			}
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		 cout<<a[i]<<endl;
	}
	return 0;
}
