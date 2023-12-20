#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,k;
ll s[20010];
ll dp[20010];
int main()
{
 cin>>n>>k;
 for(int i=0;i<n;i++)
 {
  cin>>s[i];
  dp[i]=s[i];
 }
 for(int i=1;i<k-1;i++)
 {
  dp[i]=max(dp[i-1],dp[i]);
 }
 for(int i=k-1;i<n;i++)
 {
  for(int j=0;j<i-k;j++)
  {
   dp[i]=max(dp[i],dp[j]+s[i]);	
  }
 }
 cout<<dp[n-1]<<endl;
}
