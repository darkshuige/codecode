#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=200005;
signed main()
{
	jiasu;
	int n,m;
	string s,t;
	cin>>n>>m>>s>>t;
	for(int i=0;i<(1<<m)-1;i++)
	{
		string cp=t;
		for(int j=0;j<m;j++)
		{
			int op=((i>>j) & 1);
			if(op) cp[j]='?';
		}
		//cout<<cp<<endl;
		int pos=s.find(cp);
		while(pos!=string::npos)
		{
			for(int k=pos;k<pos+t.size();k++)
			 s[k]='?';
			pos=s.find(cp);
		}
	//	cout<<s<<endl<<endl;
	}
	int flag=1;
	for(int i=0;i<s.size();i++)
	 if(s[i]!='?') flag=0;
	if(flag)
	 cout<<"Yes"<<endl;
	else
	 cout<<"No"<<endl;
	return 0;
} 
