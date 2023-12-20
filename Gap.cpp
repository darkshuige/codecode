#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
string a[10][10];
string ed="1112131415161700212223242526270031323334353637004142434445464700";
map<string,int>vis,d;
string f()
{
	string ans;
	for(int i=0;i<4;i++)
     for(int j=0;j<8;j++)
	  ans+=a[i][j];
	return ans;
}
int check(string s)
{
	int flag=1;
	for(int i=0;i<64;i+=16)
	{
		for(int j=i;j<i+16;j+=2)
		{
			if(s[j]=='0' && s[j+1]=='0')
			{
				if(s[j-1]!='7')
				 flag=0;
			}
		}
	}
	return flag;
}
void bfs()
{
	queue<string>q;
	string cp=f();
	q.push(cp);
	vis[cp]=1;d[cp]=0;
	while(!q.empty())
	{
		string op=q.front();q.pop();
		if(check(op)) return ;
		for(int i=0;i<4;i++)
		{
			string opp=op;
			string s=opp.substr(i*16,16);
			int p1=s.find("00");
			string cp=s.substr(p1-2,2);
			if(cp[1]=='7') continue;
			cp[1]=cp[1]+1;
			int p=opp.find(cp);
			opp[p]='0';opp[p+1]='0';
			opp[i*16+p1]=cp[0];opp[i*16+p1+1]=cp[1];
			if(vis.count(opp)) continue;
			vis[opp]=1;
			d[opp]=d[op]+1;
			q.push(opp);
		}
	}
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		d.clear();vis.clear();
		for(int i=0;i<4;i++)
		{
			for(int j=1;j<8;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=="11" || a[i][j]=="21" || a[i][j]=="31" || a[i][j]=="41")
				 a[i][j]="00";
			}
		}
		a[0][0]="11";a[1][0]="21";a[2][0]="31";a[3][0]="41";
		bfs();
		if(d.count(ed)==1)
		 cout<<d[ed]<<endl;
		else
		 cout<<-1<<endl;
	}
	return 0;
} 
