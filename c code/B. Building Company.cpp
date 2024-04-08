#include<bits/stdc++.h>
#define mp make_pair 
using namespace std;
#define fi first
#define se second
int q[100005];
int m[100005],vis[100005];
int sum[100005];
vector<pair<int,int> > v[100005];
queue<int> qq;
priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > p[100005];
int main() 
{
	int g,summ=0;
	cin >> g;
	for (int i = 1; i <= g; ++i) 
	{
		int a,b; cin>>a>>b;
		q[a]=b;
	}
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) 
	{
		cin>>m[i];
		for (int j = 1; j <= m[i]; ++j) 
		{
			int x, y;
			cin >> x >> y;
			p[x].push(mp(y, i));
		}
		int kk; cin>>kk;
		v[i].push_back({kk,0});
		for (int j = 1; j <= v[i][0].first; ++j) 
		{
			int a,b; cin>>a>>b;
			v[i].push_back({a,b});	
		}
	}
	for (int i = 1; i <= g; ++i) 
	{
		while (p[i].top().fi >= q[i]) 
		{
			int tt = p[i].top().se;
			sum[tt]++;
			if (sum[tt] == v[i][0].fi) 
			{
				qq.push(i);
				vis[i] = 1;
				summ++;
			}
			p[i].pop();
		}
	}
	while (!qq.empty()) 
	{
		int now = qq.front();
		for (int i = 1; i <= v[now][0].first; ++i) 
		{
			int fi = v[now][i].fi, se = v[now][i].se;
			q[fi] += se;
			while (p[fi].top().fi >= q[i]) 
			{
				int tt = p[fi].top().se;
				sum[tt]++;
				if (vis[tt] > 0) 
				{
					p[fi].pop();
				}
				if (sum[tt] == v[i][0].first) 
				{
					qq.push(i);
					vis[i] = 1;
					summ++;
				}
				p[fi].pop();
			}
		}
	}
	cout << summ << endl;

}