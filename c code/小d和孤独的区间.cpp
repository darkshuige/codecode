#include<bits/stdc++.h>
using namespace std;
int n,x;
int s[1000010];
int main()
{
 cin>>n;
 long long int sum=0,t=1;
 s[0]=0;
 for(int i=1;i<=n;i++)
 {
  cin>>x;
  if(x==1)s[t++]=i;
 }
 s[t]=n+1;
 for(int i=1;i<t;i++)
 {
  if(s[i+1]!=s[i] && s[i]!=s[i-1])
   sum+=(s[i+1]-s[i])*(s[i]-s[i-1]);
 }
 cout<<sum<<endl;
}
