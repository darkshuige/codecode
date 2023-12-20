#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int s[1000010];
int q[1000010];
int t,x,n,k;
void begin(){
 memset(s,0,sizeof(s));
 s[1]=0;
 for(int i=2;i<1000010;i++)
 {
  if(s[i]==0)
  {
  for(int j=2*i;j<1000010;j+=i)
  {
   s[j]=1;
  }
 }
 }
}

int main()
{
 begin();
 cin>>t;
 while(t--)
 {
  cin>>x>>n>>k;
  int y=0;
  int m=0;
  for(int i=1;i<=n;i++)
  {
   if(s[i]==0)
   {
    q[y++]=i;
   }
  }
  for(int i=1;i<=n;i++)
  {
   if(s[i]==1)
   {
    q[y++]=i;
   }
  }
  for(int i=0;i<n;i++)
  {
   if(q[i]==k)
   {
    m=i+1;break;
   }
  }
  if(x==1)
  {
   cout<<m<<endl;
  }
  if(x==2)cout<<q[k-1]<<endl;
 }
}
