#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

string ed; //Ä¿±ê´®
queue<string> q; //¶ÓÁÐ<×´Ì¬´®>
map<string,string> mp; //¹þÏ£<×´Ì¬´®,²Ù×÷´®>

void moveA(string x){
  string y=x;
  for(int i=0;i<4;i++) swap(x[i],x[7-i]);
  if(mp.count(x)==0)q.push(x), mp[x]=mp[y]+'A';
}
void moveB(string x){
  string y=x;
  x[0]=y[3],x[1]=y[0],x[2]=y[1],x[3]=y[2],
  x[4]=y[5],x[5]=y[6],x[6]=y[7],x[7]=y[4];
  if(mp.count(x)==0)q.push(x), mp[x]=mp[y]+'B';
}
void moveC(string x){
  string y=x;
  x[1]=y[6],x[2]=y[1],x[5]=y[2],x[6]=y[5];
  if(mp.count(x)==0)q.push(x), mp[x]=mp[y]+'C';
}
void bfs(){
  q.push("12345678"); mp["12345678"]="";
  while(q.size()){
    string s=q.front(); q.pop();
    moveA(s); moveB(s); moveC(s);
    if(mp.count(ed)){
      cout<<mp[ed].size()<<endl<<mp[ed];
      return;
    }
  }
}
int main(){
  char c;
  for(int i=0;i<8;i++)cin>>c, ed+=c;
  bfs();
}
