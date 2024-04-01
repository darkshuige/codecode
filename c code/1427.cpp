#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int maxn=INT_MIN;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			sum-=a;
			sum+=b;
			if(sum>maxn)
			 maxn=sum;
		}
		cout<<maxn<<endl;
	}
	return 0;
}
