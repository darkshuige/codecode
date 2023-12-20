#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n" 
using namespace std;
const int maxn=200005;
vector<int> graph[maxn];
int inDegree[maxn];
int flag[maxn];
void tp(int n)
{
	memset(flag,0,sizeof flag);
	queue<int> node;
	for(int i=1;i<=n;i++)
	{
		if(inDegree[i]==0)
		{
			node.push(i);
			flag[i]=1;
		}
	}
	int number=0;
	while(!node.empty())
	{  
		int u=node.front();
		node.pop();
		number++;
		for(int i=0;i<graph[u].size();i++)
		{
		    int v=graph[u][i];
		    inDegree[v]--;
		    if(inDegree[v]==0)
			{
		        node.push(v);
		        flag[v]=1;
		    }
		}
	}
}
signed main()
{
	jiasu;
    int n;
    cin>>n;
    memset(graph,0,sizeof(graph));
    memset(inDegree,0,sizeof(inDegree));
    for(int i=1;i<=n;i++)
    {
    	int to;
    	cin>>to;
    	graph[i].push_back(to);
        inDegree[to]++;
	}
    tp(n);
    int i=1;
    while(flag[i]==1)
     i++;
    int pos=i;
    queue<int>q;
    q.push(i);
    i=graph[i][0];
    while(i!=pos)
    {
    	q.push(i);
    	i=graph[i][0];
	}
	cout<<q.size()<<endl;
	int cnt=0;
	while(!q.empty())
	{
		if(cnt!=0)
		 cout<<" ";
		cnt++;
		cout<<q.front();
		q.pop();
	}
	cout<<endl;	
   return 0;
}

