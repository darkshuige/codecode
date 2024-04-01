#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cou.tie(0)
#define int long long
#define endl "\n"
using namespace std;
char res[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
signed main() 
{
	int n,x,y;
	cin>>n>>x>>y;
	int a=(2*n-x+2)*(x-1)/2+y-1;
	a%=26;
	cout<<res[a]<<endl;
    return 0;
}