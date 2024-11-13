
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;double p,r,ans;
vector<int> G[maxn];
int sum[maxn];
void dfs(int rt,int step){
    int ok=1;
    for(int i=0;i<G[rt].size();++i){
        int v=G[rt][i];ok=0;
        dfs(v,step+1);
    }
    if(ok){
        ans+=p*pow(1+r*0.01,step)*sum[rt];    
    }    
}
int main(){
    scanf("%d %lf %lf",&n,&p,&r);
    for(int i=0,x;i<n;++i){
        scanf("%d",&x);
        if(x>0){
            for(int j=1,y;j<=x;++j)
                scanf("%d",&y),G[i].push_back(y);
        }else{
            scanf("%d",&x);
            sum[i]=x;                
        }
    }
    dfs(0,0);printf("%.1f\n",ans);    
    return 0;
} 