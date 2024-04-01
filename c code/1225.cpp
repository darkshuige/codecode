#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main() 
{
    int t,n;
    cin>>t;
    a[1] = 1;
    a[2] = 2;
    while(t--)
    {
        cin>>n;
        for(int i = 3;i <= n;i++)
        {
            if(i % 2 != 0)
            {
                a[i] = a[i - 1];
            }
            else
			{
                a[i] = a[i / 2] + a[i - 2];
            }
            a[i] %= 1000000000;
        }
        cout<<a[n]<<endl;
       
    }
    return 0;
}
