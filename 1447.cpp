#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(int a)
{
    if(a>100 || a<0)
        return false;
    else
        return true;
}
int main()
{
    double x1,y1,x2,y2;
    while(~scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2))
	{
        if(x1==x2 || y1==y2)
		{
            printf("100.00\n");
            continue;
        }
        double k=(y2-y1)/(x2-x1),b=y1-k*x1,z=0;
        double dx[4],dy[4]; 
        dx[0]=0;dy[0]=b;
        dx[1]=100;dy[1]=k*100+b;
        dy[2]=0;dx[2]=-1*b/k;
        dy[3]=100;dx[3]=(100-b)/k;
        for(int i=0;i<4;i++)
		{
            for(int j=i+1;j<4;j++)
			{
                if(!check(dx[i]) || !check(dy[i]) || !check(dx[j]) || !check(dy[j]))
                 continue;
                if(dx[i]==dx[j] || dy[i]==dy[j])
                 continue;
                z=sqrt((dx[i]-dx[j])*(dx[i]-dx[j])+(dy[i]-dy[j])*(dy[i]-dy[j]));
            }
        }
        printf("%.2f\n",z);
    }
    return 0;
}
