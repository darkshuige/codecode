#include<stdio.h>
int main()
{
    float p,q;
    int i;
      while(scanf("%f%f", &p, &q)==2)
      {
    for(i = 1; ; i++) 
	{
        if((int)(i*q/100.0)-(int)(i*p/100.0) == 1) 
		{
            printf("%d\n",i);
            break;
        }
    }
}
 
    return 0;
}
