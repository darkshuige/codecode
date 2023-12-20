#include<stdio.h>
#include<math.h>
int main()
{
    int n,m;
    double sum,k;
    while(~scanf("%d%d",&n,&m))
    {
        sum=0;
        for(int i=1;i<n;i++)//一个点不动
        {
            k=(double)i/n*(n+m);//算这个点在n+m个长度当中的坐标
            sum+=fabs(k-floor(k+0.5))/(n+m);//距离相减
        }
        printf("%.4f\n",sum*10000);
    }
    return 0;
}
