#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=33000;
int n,w,v,p,q;
int mw[maxn],mv[maxn],fw[maxn][3],fv[maxn][3];//mv,mw装主键 fw和fc装附件
int f[maxn];
signed main()
{
	jiasu;
	cin>>w>>n;
	memset(f,0,sizeof f);memset(fw,0,sizeof fw);memset(fv,0,sizeof fv);
	for(int i=1;i<=n;i++)
	{
		cin>>v>>p>>q;
		if(!q)
		{
			mw[i]=v;
			mv[i]=v*p;
		}
		else
		{
			fw[q][0]++;//0用来装个数，后面的用来装每一个的v和v*p
			fw[q][fw[q][0]]=v;
			fv[q][fw[q][0]]=v*p;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=w;j>=mw[i];j--)//分四种情况
		{
			f[j]=max(f[j],f[j-mw[i]]+mv[i]);//只选m的情况
			
			if(j>=mw[i]+fw[i][1]) //选m,a
			 f[j]=max(f[j],f[j-mw[i]-fw[i][1]]+mv[i]+fv[i][1]);
			
			if(j>=mw[i]+fw[i][2]) //选m,b
			 f[j]=max(f[j],f[j-mw[i]-fw[i][2]]+mv[i]+fv[i][2]);
			 
			if(j>=mw[i]+fw[i][1]+fw[i][2]) //选m,a,b
			 f[j]=max(f[j],f[j-mw[i]-fw[i][1]-fw[i][2]]+mv[i]+fv[i][1]+fv[i][2]);
		}
	}
	cout<<f[w]<<endl;
	return 0;
} 
