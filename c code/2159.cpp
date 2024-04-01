#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	memset(a,0,sizeof a);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	sort(a+1,a+n+1);
	int op;
	while(cin>>op)
	{
		int pos=lower_bound(a+1,a+n+1,op)-a;
		cout<<pos<<endl;
	}
	return 0;
} 
