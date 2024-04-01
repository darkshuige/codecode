#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a,b;
		cin>>a>>b;
		int res=b-a;
		if(b>=12 && a<12)
		 res--;
		if(b==24)
		 res--;
		cout<<res<<endl;
	}
	return 0;
}
