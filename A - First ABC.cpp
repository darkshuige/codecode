#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int n;
	int flag1=0,flag2=0,flag3=0;
	cin>>n;
	int cnt=0;
	while(flag1==0 || flag2==0 || flag3==0)
	{
		char op;
		cin>>op;
		cnt++;
		if(op=='a' || op=='A')
		 flag1++;
		if(op=='b' || op=='B')
		 flag2++;
		if(op=='c' || op=='C')
		 flag3++;
	}
	cout<<cnt<<endl;
	return 0;
}

