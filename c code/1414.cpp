#include<stdio.h>
#include<math.h>
int main()
{
    int n=0,x=0;
    while(~scanf("%d",&n))
	{
        x=(int)(sqrt(n));
        printf("%d\n",n-x);
    }
    return 0;
}
