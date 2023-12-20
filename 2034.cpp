#include<bits/stdc++.h>
using namespace std;
const int maxn=3000;   
int a[maxn];
int main()
{
    int n;
    cin>>n;
    memset(a,0,sizeof(a));
    a[0]=1;                
    for(int i=1;i<=n;i++)
    {
        int c=0;
        for(int j=0;j<maxn;j++)  
        {
            int s=a[j]*i+c; 
            a[j]=s%10;    
            c=s/10;
        }
    }
    int i,j;
    for(j=maxn-1;j>=0;j--)
     if(a[j])
	  break;
    for(i=j;i>=0;i--)
	 cout<<a[i];
    return 0;
}
