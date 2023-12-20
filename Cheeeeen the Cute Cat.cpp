#include<bits/stdc++.h>
//#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int r[3010],l[3010],ans;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
		{
            int x;
            scanf("%d",&x);
            if(x==1)
			{
                r[i]=1;
                l[j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
     ans+=r[i]+l[i];
    printf("%d",ans/2); 
    return 0;
}

