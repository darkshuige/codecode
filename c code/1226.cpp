#include<stdio.h>
int a[1000005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,i;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int sum=0,maxsum=-1005,g=0;
        for(i=0; i<n; i++)
        {
            sum+=a[i];
            g++;
            if(sum<=0&&i<n-2)
            {
                g=0;
                sum=0;
            }
            if(g>1&&sum>maxsum)
            {
                maxsum=sum;
            }
        }
        g=0,sum=0;
        for(i=0; i<n; i++)
        {
            sum+=a[n-1-i];
            g++;
            if(sum<=0&&i<n-2)
            {
                g=0;
                sum=0;
            }
            if(g>1&&sum>maxsum)
            {
                maxsum=sum;
            }
        }
        if(maxsum<=0)
            printf("Game Over\n");
        else
            printf("%d\n",maxsum);
    }
    return 0;
}
