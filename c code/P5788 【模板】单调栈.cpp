#include <iostream>
#include <cstdio>
#include <algorithm>
#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#include<iomanip>
#include<string>
#include<stack>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
using namespace std;
const int maxn=5000005;
int a[maxn];
stack<int>st,ans;
signed main() 
{
    jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i];	
	for(int i=n;i>=1;i--)
	{
		while(!st.empty() && a[st.top()]<=a[i]) st.pop();
		if(!st.empty()) ans.push(st.top());
		else ans.push(0);
		st.push(i);
	}
	while(!ans.empty())
	 cout<<ans.top()<<" ",ans.pop();
    return 0;
}
