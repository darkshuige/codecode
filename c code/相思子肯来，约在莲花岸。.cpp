#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
const int maxn=20;
using namespace std;
struct node
{
	int x,y,op;
}a[maxn],b[maxn];
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i].x>>a[i].y>>a[i].op;;
	for(int i=1;i<=m;i++)
	 cin>>b[i].x>>b[i].y>>b[i].op;
	double d1[maxn][maxn],d2[maxn][maxn];
	int pos1[maxn]={0},pos2[maxn]={0},pos3[maxn]={0},pos4[maxn]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			d1[i][j]=(a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y);
			d2[j][i]=(a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y);
			if(pos1[i]==0 || d1[i][j]<d1[i][pos1[i]])
			 pos1[i]=j;
			if(pos2[i]==0 || d1[i][j]>d1[i][pos2[i]])
			 pos2[i]=j;
			if(pos3[j]==0 || d2[j][i]<d2[j][pos3[j]])
			 pos3[j]=i;
			if(pos4[j]==0 || d2[j][i]>d2[j][pos4[j]])
			 pos4[j]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		 cout<<" ";
		if(a[i].op==1)
		 cout<<pos2[i];
		else
		 cout<<pos1[i];
	}
	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		if(i!=1)
		 cout<<' ';
		if(b[i].op==1)
		 cout<<pos4[i];
		else
		 cout<<pos3[i];
	}
	cout<<endl;
	return 0;	
} 
