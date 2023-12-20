#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=10;
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	string ans(s,s.size()/2);
	int p=16;
	string res="";
	string op="";
	string qq="";
	for(int i=0;i<4;i++)
	{
		string ex="";
		int ep;
		if(i==0) ep=p;
		else if(i==1 || i==2) ep=p-1;
		else ep=p-2;
		if(ep<=0) ep+=26;
		for(int j=0;j<ans.size();j++)
		{
			char ch;
			if(ans[j]-'a'+1+ep>26)
			 ch=ans[j]-'z'+'a'-1+ep;
	 		else
			 ch=ans[j]+ep;
			ex=ex+ch;
		}
		qq=ex+qq;
	}
	ans=qq;
	while(ans.size()<m)
	{
		qq=ans;
		for(int i=1;i<=3;i++)
		{
			string ex="";
			int ep;
			if(i==1 || i==2) ep=1;
			else ep=2;
			for(int j=0;j<qq.size();j++)
			{
				char ch;
				if(qq[j]-'a'+1-ep<=0)
				 ch=qq[j]-'a'+'z'+1-ep;
		 		else
				 ch=qq[j]-ep;
				ex=ex+ch;
			}
			qq=ex+qq;
		}
		ans=qq; 
	}
	string rr(ans,ans.size()-m);
	cout<<rr<<endl;
	return 0;
} 

