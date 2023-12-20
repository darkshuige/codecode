#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
string s;
int n;
int main(){
 cin>>n;
 cin>>s;
 int w=0;
 for(int i=1;i<=n;i++)
 {
  int f=1;
  for(int j=i;j<n;j++)
  {
   if(s[j]!=s[j%i])
   {
    f=0;break;
   }
  }
  if(f&&i!=n)
  {
   w=1;break;
  }
 }
 if(w&&n!=1)cout<<"Wrong Answer\n";
 	else cout<<"Correct\n";
}
