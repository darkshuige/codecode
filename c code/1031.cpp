#include<stdio.h>
#include<math.h>
int main()
{
    int n,m;
    double sum,k;
    while(~scanf("%d%d",&n,&m))
    {
        sum=0;
        for(int i=1;i<n;i++)//һ���㲻��
        {
            k=(double)i/n*(n+m);//���������n+m�����ȵ��е�����
            sum+=fabs(k-floor(k+0.5))/(n+m);//�������
        }
        printf("%.4f\n",sum*10000);
    }
    return 0;
}
