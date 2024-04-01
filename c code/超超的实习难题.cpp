// Problem: 超超的实习难题
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/25717/H
// Memory Limit: 262144 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int N=1e5+5;
int sum,a[N],cnt=0;
vector<int>g[N];
int dfs(int x,int last){
	int s=a[x];
	for (auto v:g[x]){
		if (v!=last){
			s|=dfs(v,x);
		}
	}
	if (s==sum) cnt++,s=0;
	return s;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		sum|=a[i];
	}
	for (int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	if (cnt>1) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
