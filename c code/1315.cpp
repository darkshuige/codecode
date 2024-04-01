#include<bits/stdc++.h>
using namespace std;
int main()  
{  
    int A,B,C,D,a,b,c,d;  
    long long sum;  
    while(~scanf("%d%d%d%d%d%d%d%d",&A,&B,&C,&D,&a,&b,&c,&d))
    {  
        int i;
        i=1;  
          while(1)  
          {  
            sum=i;  
             if(sum%A==a&&sum%B==b&&sum%C==c&&sum%D==d)  
                break;  
             i++;  
          }  
          printf("%lld\n",sum);  
    }  
    return 0;  
} 
