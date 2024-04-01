#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
const int INF=1000000000;
int n,m,s,d;
int saveteam[505];
int st[505];
int mm[505][505];
int number[505];
int vis[505];
int dis[505];
int father[505];
void dijkstra()
{
	fill(dis,dis+n,INF);
	fill(vis,vis+n,0);
	fill(number,number+n,0);
	dis[s]=0;
	st[s]=saveteam[s];
	number[s]=1;
	for(int i=0;i<n;i++) 
	{
		int minn=INF,node=-1;
		for(int j=0;j<n;j++)//未收录顶点的最小值 
		{
			if(vis[j]==0 && dis[j]<minn)
			{
				minn=dis[j];
				node=j;	
			}
		}	
		vis[node]=1;
		if(node==-1)//这样的顶点不存在 
		{
			return;
		}
		for(int j=0;j<n;j++)// V的每个邻接点 
		{
			if(vis[j]==0 && (dis[node]+mm[node][j]<dis[j]) && mm[node][j]!=-1)//邻接并且小且没遍历过 
			{
				dis[j]=dis[node]+mm[node][j];
				st[j]=st[node]+saveteam[j];//从node走到j，加上j的队员
				father[j]=node;
				number[j]=number[node];
			}
			else if(vis[j]==0 && (dis[node]+mm[node][j])==dis[j] && mm[node][j]!=-1)
			{
				if(st[node]+saveteam[j]>st[j])
				{
					st[j]=st[node]+saveteam[j];
					father[j]=node;
				}
				number[j]+=number[node];
			}
		}
	}
}
int main()
{
	vector<int>ve;
	cin>>n>>m>>s>>d;
	for(int i=0;i<n;i++)
	{
		cin>>saveteam[i];
		father[i]=i;
		st[i]=saveteam[i];
	}
	memset(mm,-1,sizeof mm);
	for(int i=0;i<m;i++)
	{
		int n1,n2,value;
		cin>>n1>>n2>>value;
		mm[n1][n2]=value;
		mm[n2][n1]=value;
	}
	dijkstra();
	int p=d,sum=0;
	while(1)//从终点开始把father点放进vector里面，当p=fatherp的时候也就是回到起点 
	{
		if(p==father[p])
		{
			ve.push_back(p);
			break;
		}
		ve.push_back(p);
		p=father[p]; 
	}
	cout<<number[d]<<" "<<st[d]<<endl;
	for(int i=ve.size()-1;i>=0;i--){
        if(i==ve.size()-1)
		{
            cout<<ve[i];
        }
		else
		{
            cout<<" "<<ve[i];
        }
    }
	return 0;
}
