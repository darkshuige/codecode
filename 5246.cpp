#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int maxn=INT_MIN;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			if(a>maxn)
			 maxn=a;
		}
		cout<<maxn<<endl;
	}
	return 0;
}
