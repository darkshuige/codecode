#include<bits/stdc++.h>
using namespace std;
int isprime(int n)
{
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
         return 0;
    }
    return 1;
}
int a[110],vis[110],b[110],n,flag;
void facs(int cur)
{
    int i;
    if(cur==n && b[a[0]+a[n-1]])//满足条件了就输出
    {
        flag=1;
	    for(i=0;i<n;i++)
	    {
	        if(i==0)
	         printf("%d",a[i]);
	        else
	         printf(" %d",a[i]);
	    }
    	printf("\n");
  		return;
    }
    else
    {
        for(i=2;i<=n;i++)
        {
            if(vis[i]==0 && b[i+a[cur-1]]==1)
            {
                a[cur]=i;
                vis[i]=1;
                facs(cur+1);
                vis[i]=0;
            }
        }
    }
}
int main()
{
   int i;
   for(i=2;i<=110;i++)
   {
       b[i]=isprime(i);
   }
   while(~scanf("%d",&n))
   {
       flag=0;
	   if(n==1)
	   {
		   printf("-1\n");
		   continue;
	   }
       memset(vis,0,sizeof(vis));
       a[0]=1;
       facs(1);
       if(flag==0)
        printf("-1\n");
   }
   return 0;
}
