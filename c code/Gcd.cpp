#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int n;
	cin>>n;
	int pos=0;
	int maxn=0;
	int p=-1;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		if(i==1)
		 pos=op;
		if(op>=maxn)
		 maxn=op,p=i;	
	} 
	if(p==1)
	 cout<<0<<endl;
	else if(pos<=maxn && p!=1)
	 cout<<maxn+1-pos<<endl;
	return 0;
}
