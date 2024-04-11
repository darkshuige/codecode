#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
map<int,int>mp;
const int maxn=200;
const double PI=3.141592;
string s[maxn];
int check(string s)
{
	int ans=0;
	for(int i=1;i<=s.size();i++)
	{
		if(s[i]>='A' && s[i]<='Z')
		 ans++;
	}
	return ans;
}
signed main()
{
	int n; cin>>n;
	string ss; cin>>ss;
	for(int i=1;i<=n;i++)
	 cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		if(ss=="Camel")
		{
			int pos;
			pos=s[i].find("_");
			if(s[i][0]>='a' && s[i][0]<='z' && pos==string::npos)
			 cout<<s[i]<<endl;
			else if(s[i][0]>='A' && s[i][0]<='Z')
			{
				s[i][0]=tolower(s[i][0]);
				cout<<s[i]<<endl;
			}
			else if(pos!=string::npos)
			{
				for(int k=0;k<s[i].size();k++)
				{
					if(s[i][k]=='_')
					{
						s[i][k+1]=toupper(s[i][k+1]);
						s[i].erase(k,1);
					}
				}
				cout<<s[i]<<endl;
			}
		}
		else if(ss=="Pascal")
		{
			int pos;
			pos=s[i].find("_");
			if(s[i][0]>='a' && s[i][0]<='z' && pos==string::npos)
			{
				s[i][0]=toupper(s[i][0]);
				cout<<s[i]<<endl;
			}
			else if(s[i][0]>='A' && s[i][0]<='Z')
			{
				cout<<s[i]<<endl;
			}
			else if(pos!=string::npos)
			{
				s[i][0]=toupper(s[i][0]);
				for(int k=0;k<s[i].size();k++)
				{
					if(s[i][k]=='_')
					{
						s[i][k+1]=toupper(s[i][k+1]);
						s[i].erase(k,1);
					}
				}
				cout<<s[i]<<endl;
			}
		}
		else if(ss=="Snake")
		{
			int pos;
			pos=s[i].find("_");
			if(s[i][0]>='a' && s[i][0]<='z' && pos==string::npos)
			{
				for(int k=0;k<s[i].size();k++)
				{
					if(s[i][k]>='A' && s[i][k]<='Z')
					{
						s[i][k]=tolower(s[i][k]);
						s[i].insert(k,"_");
					}
				}
				cout<<s[i]<<endl;
			}
			else if(s[i][0]>='A' && s[i][0]<='Z')
			{
				s[i][0]=tolower(s[i][0]);
				for(int k=1;k<s[i].size();k++)
				{
					if(s[i][k]>='A' && s[i][k]<='Z')
					{
						s[i][k]=tolower(s[i][k]);
						s[i].insert(k,"_");
					}
				}
				cout<<s[i]<<endl;
			}
			else if(pos!=string::npos)
			{
				cout<<s[i]<<endl;
			}
		}
	}
	return 0;
} 	