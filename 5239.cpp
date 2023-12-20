#include <stdio.h>
int a[305],b[1000005];
int main()
{
    int n,w,i,s,z,cnt=0;
    scanf("%d%d",&n,&w);    
    for(i=0;i<n;i++)
	 scanf("%d",&a[i]),b[a[i]]=1;
    for(i=0;i<n;i++)
	{		
        for(s=i+1;s<n;s++)
		{	
            if(a[i]+a[s]<=w) b[a[i]+a[s]]=1;
        }									
    }
    for(i=0;i<n;i++)
	{
        for(s=i+1;s<n;s++)
		{
            for(z=s+1;z<n;z++)
			{		
                if(a[i]+a[s]+a[z]<=w) b[a[i]+a[s]+a[z]]=1;
            }
        }
    }
    for(i=1;i<=w;i++) 
	 if(b[i]==1) 
	  cnt++;
    printf("%d\n",cnt);
    return 0;
} 
