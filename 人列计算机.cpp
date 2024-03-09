#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100;
string a[maxn];
signed main()
{
	jiasu;
	string b;
	getline(cin,b);
	for(int i=1;i<=3;i++) getline(cin,a[i]);
	getline(cin,b);
	if(a[2][5]=='1')//非们
	{
		if(a[2][0]=='0')
		 cout<<1<<endl;
		else
		 cout<<0<<endl;
	}
	else if(a[2][5]=='&')
	{
		int aa=a[1][0]-'0';
		int bb=a[3][0]-'0';
		cout<<(aa & bb)<<endl;
	}
	else
	{
		int aa=a[1][0]-'0';
		int bb=a[3][0]-'0';
		cout<<(aa | bb)<<endl;
	}
	return 0;
} 
