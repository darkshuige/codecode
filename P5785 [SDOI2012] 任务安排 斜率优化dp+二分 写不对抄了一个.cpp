#include <iostream>
#include <cstring>
#include <algorithm>
#define N 300010
#define LL long long
using namespace std;

int n,s,h=1,t=0,q[N];
LL c[N],tim[N],f[N];

LL dy(int j,int k){return f[j]-f[k];}
LL dx(int j,int k){return c[j]-c[k];}
int find(int i){
  if(h==t) return q[h];
  int l=h-1,r=t+1;
  while(l+1<r){
    int m=l+r>>1;
    if(dy(q[m],q[m-1])<=dx(q[m],q[m-1])*(tim[i]+s)) l=m;
    else r=m;
  }
  return q[l];
}
int main(){
  scanf("%d%d",&n,&s);
  for(int i=1;i<=n;i++){
    scanf("%lld%lld",tim+i,c+i);
    tim[i]+=tim[i-1]; c[i]+=c[i-1];
  }
  
  for(int i=1;i<=n;i++){
    while(h<t && dy(i-1,q[t])*dx(q[t],q[t-1])<=dx(i-1,q[t])*dy(q[t],q[t-1])) t--;
    q[++t]=i-1;    
    int j=find(i);
    f[i]=f[j]+tim[i]*(c[i]-c[j])+s*(c[n]-c[j]);
  }
  printf("%lld\n",f[n]);
}