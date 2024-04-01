#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int t,n,m;
int mod=128;
map<string,int>mp;
string x,w,s;
int p[100010];
int main(){
 cin>>t;
 while(t--){
  cin>>n>>m;
  memset(p,0,sizeof(p));
  for(int i=1;i<=m;i++){
   cin>>x>>s;
   mp[s]++;
  }
  cin>>w;
  map<string,int>::iterator it;
  p[0]=1;
  int flag=0;
  for(int i=1;i<=n;i++){
   for(it=mp.begin();it!=mp.end();it++){
    string pop=it->first;
    int ko=it->second;
    int nl=pop.size();
    if(pop.size()<=i){
     string bob=w.substr(i-nl,nl);
     if(bob==pop){
      p[i]+=p[i-nl]*ko;
      if(p[i]>0&&p[i]%128==0)p[i]=128;
      else if(p[i]>1&&p[i]%128==1)p[i]=129;
      else p[i]%=128;
     }
     
     }
    }
    
  }
  
   if(p[n]==0)cout<<"nonono\n";
   else if(p[n]==1)cout<<"happymorsecode\n";
   else cout<<"puppymousecat "<<p[n]%128<<endl;
  
   
   mp.clear();
 }
  
}
