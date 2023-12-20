#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244853
map<int, map<int, map<int, int>>> mp;
int arr[300005];
//费马小求逆元 
ll ksm(ll x, ll n, ll p)
{
	ll tmp = 1;
	while(n != 0)
	{
		if(n & 1)
		{
			tmp *= x;
			tmp %= p;
		}
		n /= 2;
		x *= x;
		x %= p;
	}
	return tmp % p;
}
ll inv(ll a, ll p)
{
	return ksm(a, p - 2, p);
}
 
 
int main()
{
	ios::sync_with_stdio(false);
	int n, m, k;
	while(cin >> n >> m >> k)
	{
		mp.clear();
		//建图 
		for(int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			mp[u][v][w]++;
			mp[v][u][w]++;
		}
		//路径输入 
		for(int i = 1; i <= k; i++)
		{
			cin >> arr[i];
		}
		ll sum = 0; //求总的预算
		ll cnt = 1; //求总路径数量 
		bool f = 0;  //判断能否连通 
		for(int i = 2; i <= k; i++)
		{
			if(mp[arr[i - 1]][arr[i]].size() == 0)
			{//判断是否有路径 
				f = 1;
				break;
			}
			ll ans = 0;
			for(auto l : mp[arr[i - 1]][arr[i]])
			{
				ans += l.second;
				ans %= mod;
			}
			cnt *= ans;
			cnt %= mod; 
		}
		if(f)
		{
			cout << "Stupid Msacywy!" << endl;
		}
		else
		{
			sum = 0;
			for(int i = 2; i <= k; i++)
			{
				ll ans = 0;
				sum *= 10;
				sum %= mod;
				for(auto l : mp[arr[i - 1]][arr[i]])
				{
					ans += l.second;
					ans %= mod;
				}
				for(auto l : mp[arr[i - 1]][arr[i]])
				{
					sum += (((l.first * l. second % mod) * cnt % mod)* inv(ans, mod) % mod) % mod;
					sum %= mod;
				}
			}
			cnt = inv(cnt, mod);
			cout << sum * cnt % mod << endl;
		}
	}
	return 0;
}
