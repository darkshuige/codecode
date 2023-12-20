#include<bits/stdc++.h>
using namespace std;
int a[]={11,22,33,44,55,66,77,88,99,111,222,333,444,555,666,777,888,999,1111,2222,3333,4444,5555,6666,7777,8888,9999,11111,22222,33333,44444,55555,66666,77777,88888,99999,111111,222222,333333,444444,555555,666666,777777,888888,999999,1111111};
int main()
{
	int x,y;
	while(cin>>x>>y)
	{
		int l=lower_bound(a,a+46,2*x)-a;//找到大于等于2*x的位置 
        int r=upper_bound(a,a+46,2*y)-a-1;//找到大于2*y的位置-1
        int sum=0;
        for(int i=l;i<=r;i++)
        {
            if(a[i]-x<=y)
            {
                int n=(a[i]-x)-x+2;
                sum+=n/2;
            }
            else
            {
                int n=y-(a[i]-y)+2;
                sum+=n/2;
            }
        }
        printf("%d\n",sum);

	} 
	return 0;
} 
