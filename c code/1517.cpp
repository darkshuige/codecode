#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
    int t,n,i,j,temp;
    int count1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        count1=0;
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[i])
                {
                    count1++;
                    break;
                }
            }
        }
        printf("%d\n",count1);
    }
    return 0;
}
