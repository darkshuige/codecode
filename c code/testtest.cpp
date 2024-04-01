#include <iostream>
#include <cstring>
#include <algorithm>
#define N 3010
#define M 310
using namespace std;

int n,m,x[N];
int w[N][N]; //w[i,j]表示村庄[i,j]之间建一个邮局的最小距离和
int f[N][M]; //f[i,j]表示前i个村庄建j个邮局的最小距离和
int p[N][M]; //p[i,j]表示状态f[i,j]的最优决策点

int main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>x[i];
  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      w[i][j]=w[i][j-1]+x[j]-x[(i+j)/2];
      
  memset(f,0x3f,sizeof(f)); f[0][0]=0;
  for(int i=1;i<=m;i++) p[n+1][i]=n;
  
  for(int j=1;j<=m;j++)                    //枚举邮局
    for(int i=n;i>=j;i--)                  //枚举村庄
      for(int k=p[i][j-1];k<=p[i+1][j];k++)//枚举决策
        if(f[i][j]>f[k][j-1]+w[k+1][i])
          f[i][j]=f[k][j-1]+w[k+1][i], p[i][j]=k;   
  cout<<f[n][m];  
}