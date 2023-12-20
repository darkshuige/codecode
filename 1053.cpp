#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n,i,count1,count2,count3,j;
    int p=1;
    int a[10001];
    int b[10001];
    int c[10001];
    while(~scanf("%d",&n))
    {
        if(n==0)
         break;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(i=0;i<n;i++)
         scanf("%d",&a[i]);
        printf("Game %d:\n",p++);
        while(1)
        {
            count1=0;
            count2=0;
            count3=0;
            memset(b,0,sizeof(b));
            for(i=0;i<n;i++)
            {
                scanf("%d",&b[i]);
                c[i]=a[i];
                if(b[i]==0)
                 count3++;
            }
            if(count3==n)
             break;
            for(i=0;i<n;i++)
            {
                if(c[i]==b[i])
                {
                    c[i]=0;
                    b[i]=0;
                    count1++;
                }
            }
            for(i=0;i<n;i++)
            {
	            if(c[i]!=0)
	            {
	                for(j=0;j<n;j++)
	                {
	                    if(c[i]==b[j])
	                    {
	                        count2++;
	                        c[i]=0;
	                        b[j]=0;
	                        break;
	                	}
	                }
                }
            }
	        printf("    (%d,%d)\n",count1,count2);
	    }
	}
	return 0;
}
