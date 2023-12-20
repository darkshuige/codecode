#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a[4];
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        if(a[2]>=(a[1]+a[0])*2)
            printf("%d\n",a[1]+a[0]);
        else
        {
            int z=(a[2]+a[1]+a[0])/3;
            printf("%d\n",z);
        }
    }
    return 0;
}
