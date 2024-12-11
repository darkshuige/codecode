#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=5050;
char ans[maxn][maxn];
signed main()
{
	string s; cin>>s;
	int n1,n2;
	int t=s.size()+2;
	n2=ceil(1.0*t/3);
	while((t-n2)%2!=0) n2++;
	n1=(t-n2)/2;
	int x=0,y=0,ct=0;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		 ans[i][j]=' ';
	}
	for(int i=0;i<n1;i++)
	 ans[x++][y]=s[ct++];
	x--;
	for(int i=0;i<n2-1;i++)
	 ans[x][++y]=s[ct++];
	for(int i=0;i<n1-1;i++)
	 ans[--x][y]=s[ct++];
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		 cout<<ans[i][j];
		cout<<endl;
	}
	return 0;
} 
