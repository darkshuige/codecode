#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ull unsigned long long
using namespace std;
const int maxn=100005;
int ch[maxn][26];
int cnt[maxn];
int index;
void insert(char a[])
{
	int p=0;
	for(int i=0;i<strlen(a);i++)
	{
		int j=a[i]-48;
		if(!ch[p][j])
		 ch[p][j]=++index;
		p=ch[p][j];
	}
	cnt[p]++;
}
int query(char a[])
{
	int p=0;
	for(int i=0;i<strlen(a);i++)
	{
		int j=a[i]-48;
		if(!ch[p][j])
		 return 0;
		p=ch[p][j];
	}
	return cnt[p];
}
signed main()
{
	jiasu;
	index=0;
	return 0;
}
