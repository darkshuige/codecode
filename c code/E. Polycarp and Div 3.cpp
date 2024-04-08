#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=200005;
int f[maxn][2],now[maxn][2];
signed main()
{
	jiasu;
	string s; cin>>s;
	int n=s.size();
	int cnt=0,now=0;
	s+="#####";
	for(int i=0;i<n;i++)
	 s[i]=((s[i]-'0')%3)+'0';
	int pos=0;
	while(pos<n)
	{
		if(s[pos]=='0')
		{
			cnt++;
			pos+=1;
		}
		else if(s[pos]=='1' && s[pos+1]=='2')
		{
			cnt++;
			pos+=2;
		}
		else if(s[pos]=='2' && s[pos+1]=='1')
		{
			cnt++;
			pos+=2;
		}
		else if(s[pos]=='1' && s[pos+1]=='1' && s[pos+3]=='1')
		{
			cnt++;
			pos+=3;
		}
		else pos++;
	}
	cout<<cnt<<endl;
	return 0;
} 
