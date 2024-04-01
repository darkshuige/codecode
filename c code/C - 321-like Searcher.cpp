#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
vector<int>a;
void dfs(int op)
{
	a.push_back(op);
	if(op%10==0) return ;
	for(int i=0;i<op%10;i++)
	{
		dfs(op*10+i);
	}
}
signed main()
{
    jiasu;
    int k;
    cin>>k;
    for(int i=1;i<=9;i++)
     dfs(i);
    sort(a.begin(),a.end());
    cout<<a[k-1]<<endl;
    return 0;
}
