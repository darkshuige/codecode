#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;
char part[]={'A', 'T', 'G', 'C'};
int pos[10] = { 0 };
int dep,n;
string dna[maxn];
int f()
{
	int ans=0;
	int cnt[4]={0};
	int ma[4]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=pos[i];j<dna[i].size();j++)
		{
			if(dna[i][j]=='A') cnt[0]++;
			if(dna[i][j]=='T') cnt[1]++;
			if(dna[i][j]=='G') cnt[2]++;
			if(dna[i][j]=='C') cnt[3]++;
		}
		for(int k=0;k<4;k++)
		{
			ma[k]=max(ma[k],cnt[k]);
			cnt[k]=0;
		}
	}
	for(auto i:ma)
	{
		ans+=i;
	}
	return ans;
}
int idastar(int u)
{
	int ff=f();
	if(u+ff>dep) return 0;
	if(ff==0) return 1;
	int tem[10];
	memcpy(tem,pos,sizeof tem);
	for(int i=0;i<4;i++)//选part里面的 
	{
		int flag=0;//看是否有一个能匹配 
		for(int j=0;j<n;j++)
		{
			if(dna[j][pos[j]]==part[i])
			{
				pos[j]++;
				flag=1;
			}
		}
		if(flag==1)
		{
			if(idastar(u+1)==1)
			 return 1;
		}
		memcpy(pos,tem,sizeof pos);
	}
	return false;
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ma=1;
		for(int i=0;i<n;i++)
		{
			cin>>dna[i];
			int len=dna[i].size();
			ma=max(ma,len);
		}
		for(dep=ma;;dep++)
		{
			memset(pos,0,sizeof pos);
			if(idastar(0)==1)
			 break;
		}
		cout<<dep<<endl;
	}
	return 0;
}
