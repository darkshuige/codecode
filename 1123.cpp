#include<stdio.h>
#include<math.h>
int main()
{
    int a,i,m,n,b,x;
    while(scanf("%d%d%d%d",&n,&m,&a,&b)!=EOF)
    {
        x=0;
        while(n>=m)
        {
            x++;
            n-=a;
            if(n<m)
                break;
            if(b>=a)
            {
                x=-1;
                break;
            }
            n+=b;
        }
        if(x>=0)
         printf("%d\n",x);
        else
         printf("impossible\n");
    }
    return 0;
}

