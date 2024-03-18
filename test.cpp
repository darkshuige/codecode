#include<cstdio>
#include<cstring>
#include<iostream>
#define N 205
using namespace std;

int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
char map[N][N];
int n,m,sx,sy,K, ans,f[N][N];
struct node{int f,pos;} q[N]; //最长距离f,位置pos

//起点坐标x,y，行列长度L，时区长度tim，方向d
void DP(int x,int y,int L,int tim,int d){
  int h=1,t=0;
  for(int i=1;i<=L;i++,x+=dx[d],y+=dy[d]){
    if(map[x][y]=='x') h=1,t=0; //遇到障碍，清空队列
    else{
      while(h<=t && q[t].f+i-q[t].pos<=f[x][y]) t--;
      q[++t]=node{f[x][y],i};
      if(q[h].pos<i-tim) h++;
      f[x][y]=q[h].f+i-q[h].pos;
      ans=max(ans,f[x][y]);
    }
  }
}
int main(){
  scanf("%d%d%d%d%d",&n,&m,&sx,&sy,&K);
  for(int i=1;i<=n;i++) scanf("%s",map[i]+1);
  memset(f,-0x3f,sizeof(f)); f[sx][sy]=0;
  for(int k=1,s,t,d,tim;k<=K;k++){    //枚举k个时间区间
    scanf("%d%d%d",&s,&t,&d); tim=t-s+1;
    if(d==1) for(int i=1;i<=m;i++) DP(n,i,n,tim,d);//上
    if(d==2) for(int i=1;i<=m;i++) DP(1,i,n,tim,d);//下
    if(d==3) for(int i=1;i<=n;i++) DP(i,m,m,tim,d);//左
    if(d==4) for(int i=1;i<=n;i++) DP(i,1,m,tim,d);//右
  }
  printf("%d",ans);
}