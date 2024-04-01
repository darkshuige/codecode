#include<stdio.h>
#include<algorithm>
using namespace std; 
int main()
{
 int n;
 long long m;
 int a[100005];
 int i,k=0;
 scanf("%d %lld",&n,&m);
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 sort(a,a+n);
 for(k=0;k<n;k++)
 {
  m-=a[k];
  if(m<0)
  {
   break;
  }
 }
 printf("%d\n",k);
 return 0;
}
