#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int f[maxn][3],n,vis[maxn];
vector<int>g[maxn];
void dp(int u)
{
	f[u][0]=1;//��ʾ�Լ�Ҫ�� 
	f[u][1]=0;//��ʾ���ӽڵ㸲�� 
	f[u][2]=0;//��ʾ�����ڵ㸲��
	vis[u]=1;
	int flag=0;
	int inc=INF;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];//�ӽڵ�
		if(vis[v]==0)
		{
			dp(v);//�ݹ�
			f[u][0]+=min(f[v][0],min(f[v][1],f[v][2]));//uҪ�ã�����νv���ò��ã���������С��
			f[u][2]+=min(f[v][0],f[v][1]);//��Ϊu�ڵ�û�ã�����v�ڵ㲻���ܱ����ڵ㸲��	
			if(f[v][0]<f[v][1])//��ʼ����f[u][1]�����ӽڵ㸲�ǵ���� 
			{
				flag=1;//�������Ҫ���ӽڵ����� 
				f[u][1]+=f[v][0];//���´�ֱ���� 
			}
			else
			{
				inc=min(inc,(f[v][0]-f[v][1]));//incҪ��С�� 
				f[u][1]+=f[v][1];//��Ȼ����С�ĵ���Ҫ��¼incֵ 
			}		 
		}
	}
	if(flag==0)//f[u][1]û�д�f[v][0]�ƹ�����ǿ��ת��Ϊ��f[v][0]�ƹ���
	 f[u][1]+=inc;
}
signed main()
{
	jiasu;
	while(cin>>n)
	{
		memset(vis,0,sizeof vis);
		memset(f,0,sizeof f);
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dp(1);
		cout<<min(f[1][0],f[1][1])<<endl;	
	}
	return 0;
} 
