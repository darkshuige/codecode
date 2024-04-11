#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
map<int,int>mp;
const int maxn=2000;
const double PI=3.141592;
struct node
{
	char kk;
	int num;
};
deque<node>a[maxn];
signed main()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char k; cin>>k;
		node no={k,i};
		a[i].push_back(no);
	}
	while(m--)
	{
		int op,p1,p2; cin>>op;
		if(op==1)
		{
			cin>>p1>>p2;
			while(!a[p1].empty())
			{
				a[p2].push_front(a[p1].front());
				a[p1].pop_front();
			}
		}
		else if(op==2)
		{
			cin>>p1>>p2;
			while(!a[p1].empty())
			{
				a[p2].push_front(a[p1].back());
				a[p1].pop_back();
			}
		}
		else if(op==3)
		{
			cin>>p1;
			int nim=a[p1].size();
			vector<node>v;
			for(int k=0;k<nim;k++)
			{
				node no=a[p1].back();
				a[p1].pop_back();
				int fu=no.num;
				if(fu==p1)
				 v.push_back(no);
				else
				 a[fu].push_front(no);
				
				for(auto no:v)
				 a[p1].push_front(no);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		while(!a[i].empty())
//		{
//			cout<<a[i].back().kk<<" ";
//			a[i].pop_back();
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].size()==0)
		 cout<<0<<endl;
		else
		{
			string s;
			int l=0,r=0;
			while(!a[i].empty())
			{
				s+=a[i].back().kk;
				if(a[i].back().kk=='(') l++;
				if(a[i].back().kk==')') r++;
				a[i].pop_back();
			}
			int ff=1; vector<string>v;
			if(l!=r)
			{
				ff=-1;
			}
			else
			{
				string ss="";
				while(s.size())
				{
					int pos=s.find(")");
					if(pos==string::npos) break;
					int flag=0;
					for(int k=pos-1;k>=0;k--)
					{
						if(s[k]=='(')
						{
							flag=1;
							if(ss.size()!=0) v.push_back(ss);
							s.erase(k,ss.size()+2);
							ss="";
							break;
						}
						else
						 ss=s[k]+ss;
					}
					if(flag==0)
					{
						ff=-1;
						break;
					}
				}
				if(ff==1 && s.size())
				 v.push_back(s);	
			}
			
			if(ff==-1)
			 cout<<-1<<endl;
			else
			{
				if(v.size()!=0)
				 cout<<v.size()<<" ";
				for(int l=0;l<v.size();l++)
				{
					if(l!=0) cout<<" ";
					cout<<v[l];
				}
				cout<<endl;
			}
		}
	}
	return 0;
} 	