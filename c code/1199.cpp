#include<bits/stdc++.h>
using namespace std;
long long a[2015]= {0};
int b[13]= {0,31,0,31,30,31,30,31,31,30,31,30,31};
bool leapyear(int y)
{
    if((y%4==0&&y%100!=0)||y%400==0)
        return true;
    return false;
}
int main()
{
    a[2] =365;
    for(int i = 3; i <= 2013; i++)//a[i]
    {
        if(leapyear(i-1))
            a[i] += a[i-1]+366;
        else
            a[i] += a[i-1]+365;
    }
    int y,m,d,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&y,&m,&d);
        if(leapyear(y))
            b[2] = 29;
        else
            b[2] = 28;
        if(d>b[m] || m==0 || d==0 || m>12)
            printf("-1\n");
        else
        {
            long long sum = a[y];
            for(int i = 1; i < m; i++)
                sum += b[i];
            sum += d;
            printf("%d\n",sum%7);
        }
    }
    return 0;
}
