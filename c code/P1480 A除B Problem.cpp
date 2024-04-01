#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a,c;
int b,pos;

int main(){
  string A; cin>>A>>b;
  for(int i=A.size()-1; ~i; i--)
    a.push_back(A[i]-'0');
  
  long long r=0;
  for(int i=a.size()-1; ~i; i--){
    r=r*10+a[i];      //被除数
    c.push_back(r/b); //存商
    r%=b;             //余数
  }
  for(int i=0;i<c.size();i++)
    if(c[i]){pos=i; break;}
    
  for(int i=pos;i<c.size();i++)cout<<c[i];
  return 0;
}