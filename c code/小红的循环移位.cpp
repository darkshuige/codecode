#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=100005;
int a[maxn];
deque<int>de;
int check()
{
	if(de.size()==1)
	{
		if(de.front()%4==0) return 1;
		else return 0;
	}
	else
	{
		int n=de.size();
		if((de[n-2]*10+de[n-1])%4==0)
		 return 1;
		else
		 return 0;
	}
}
signed main()
{
	string s; cin>>s;
	int n=s.size();
	for(int i=0;i<s.size();i++)
	 de.push_back(s[i]-'0');
	int ans=0;
	int flag=0;
	while(n--)
	{
		if(check())
		{
			cout<<ans<<endl;
			flag=1;
			break;
		}
		ans++;
		de.push_back(de.front());
		de.pop_front();
	}
	if(!flag) cout<<-1<<endl;
	return 0;
}

