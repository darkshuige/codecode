#include<iostream>
#include<cstdio>  
using namespace std;  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
        if(n%12==0)  
        {  
            printf("YES\n");  
        }  
        else 
        {  
            if(n%4==0)  
            {  
                printf("3\n");  
            }  
            else if(n%6==0)  
            {  
                printf("4\n");  
            }  
            else 
            {  
                printf("NO\n");  
            }  
        }  
    }  
    return 0;  
}
