#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int res=0;
        n=n%9;
        for(int i=1;i<=n;i++)
        {
            res=(res+i)%9;
        }
        printf("%d\n",res);
    }
    return 0;
}
