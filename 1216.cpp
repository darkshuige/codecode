#include<bits/stdc++.h>
using namespace std;
int main()
{   int n,i,x,t,j;
    int a[1000];
    while(~scanf("%d%d",&n,&x))
	{
        for(i=0;i<n;i++) 
		{
            scanf("%d",&a[i]);
        }
        t=n+1;
        for(j=0;j<n;j++)
		{
            if(a[j]==x)
			{
               t=j;
               break;
            }
            }
        if(t<=n)
		{
            printf("%d\n",t);
        }
		else
		{
            printf("-1\n");
        }
    }
    return 0;
}
