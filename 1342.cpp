#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int t,i,j,x1,y1,x2,y2,flag,p,q;
    char c;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                cin>>c;
                if(c=='K'&&flag==0)
                {
                    flag=1;
                    x1=i;
                    y1=j;
                }
                else if(c=='K'&&flag==1)
                {
                    x2=i;
                    y2=j;
                }
            }
        }
        p=fabs(x1-x2);
        q=fabs(y1-y2);
        if(p%4==0 && q%4==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
