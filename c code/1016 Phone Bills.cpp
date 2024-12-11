#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2005;
int a[maxn];
int cost[maxn];
map<string,int>mp;
deque<string>q1[maxn],q2[maxn],ans[maxn];
string mon;
signed main()
{
	jiasu;
	for(int i=0;i<=23;i++)
	 cin>>cost[i];
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s,s1,s2; cin>>s;
		if(!mp.count(s))
		 mp[s]=i;
		cin>>s1;
		mon=s1.substr(0,2);
		cin>>s2;
		if(s2=="on-line")
		 q1[mp[s]].push_back(s1);
		else
		 q2[mp[s]].push_back(s1);
	}
	for(auto k:mp)
	{
		int id=k.second; string name=k.first;
		if(q1[id].empty() || q2[id].empty()) continue;
		cout<<name<<" "<<mon<<endl;
		string l,r;
		sort(q1[id].begin(),q1[id].end()); sort(q2[id].begin(),q2[id].end());
		while(!q1[id].empty() && !q2[id].empty())
		{
			l=q1[id].front(); q1[id].pop_front(); r=q2[id].front(); q2[id].pop_front();
			if(l<r)
			{
				while(!q1[id].empty())
				{
					if(q1[id].front()<r)
					{
						l=q1[id].front();
						q1[id].pop_front();
					}
					else break;
				}
				ans[id].push_back(l);
				ans[id].push_back(r);
			}
			else
			{
				if(!q1[id].empty() && !q2[id].empty())
				 r=q2[id].front(); q2[id].pop_front();
			}
		}
		if(ans[id].empty()) continue;
		else
		{
			double ssum=0;
			while(!ans[id].empty())
			{
				int ct=0;
				l=ans[id].front(); ans[id].pop_front(); r=ans[id].front(); ans[id].pop_front();
				int d1,h1,m1,d2,h2,m2;
				d2=(l[3]-'0')*10+(l[4]-'0'); h2=(l[6]-'0')*10+(l[7]-'0'); m2=(l[9]-'0')*10+(l[10]-'0');
				d1=(r[3]-'0')*10+(r[4]-'0'); h1=(r[6]-'0')*10+(r[7]-'0'); m1=(r[9]-'0')*10+(r[10]-'0');
				double sum=0;
				while(!(d2==d1 && h2==h1 && m2==m1))
				{
					while(h2==24)
					{
						h2-=24; d2++;
					}
					if(d2==d1 && h2==h1)
					{
						if(m2==0)
						{
							
							ct+=m1;
							sum+=cost[h2]*m1;m2+=m1;
						}
						else
						{
							ct+=(m1-m2);
							sum+=cost[h2]*(m1-m2);m2+=(m1-m2);
						}
					}
					else
					{
						if(m2==0)
						{
							ct+=60;
							sum+=cost[h2]*60;
							m2+=60;
						}
						else
						{
							ct+=(60-m2);
							sum+=cost[h2]*(60-m2);
							m2+=(60-m2);
						}
						h2++;
						m2-=60;
					}
					while(h2==24)
					{
						h2-=24; d2++;
					}
				}
				ssum+=sum;
				cout<<l.substr(3)<<" "<<r.substr(3)<<" "<<ct<<" "<<"$"<<fixed<<setprecision(2)<<sum/100<<endl;
			}
			cout<<"Total amount: $"<<fixed<<setprecision(2)<<ssum/100<<endl;
		}
	}
	return 0;
} 