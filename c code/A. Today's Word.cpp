#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,t,k,ans,x;

ll qpow(ll x,ll q)
{
	ll ans=1;
	while(q)
	{
		if(q&1) ans=ans*x%26;
		q>>=1;
		x=x*x%26;
	}
	return ans;
}

void solve()
{
	string s;
	cin>>n>>m>>s;
	string ps,ls=s.substr(s.length()/2);
	ll yw=16,cnt=0,op=0;
	ll p=16;
	for(int i=0;i<m;)
	{
		string pps;
		int flag=0;
		for(int k=0;k<4;k++)
		{
			int ep;
			if(k==0) ep=p;
			else if(k==1 || k==2) ep=p-1;
			else ep=p-2;
			if(ep<=0) ep+=26;	
			for(int j=ls.length()-1;j>=0;j--)
			{
				char ch;
				if(ls[j]-'a'+1+ep>26)
				 ch=ls[j]-'z'+'a'-1+ep;
		 		else
				 ch=ls[j]+ep;
				pps=ch+pps; 
				i++;
				if(i==m)
				{
					flag=1;
					break;
				} 
			}	
			if(flag) break;
		}
		p--;
		cnt++;
		if(p==0) p=26;
		ps=pps+ps;
		if(i==m) break;
	}
	cout<<ps<<"\n";
} 
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
//	cin>>t;
//	while(t--) solve();
}

//boc bocchi dij
//bocboc bocbocchidij next(chidij);
// chidij next(chidij) next(chidij next(chidij));
