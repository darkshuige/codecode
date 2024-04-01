#include<bits/stdc++.h> 
using namespace std;
const int maxn = 1e6 + 5;
int dp[maxn],a[maxn];
int main() 
{
    int n,m,t = 0;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
         break;
        t++;
        int count=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double x = (i*i + j*j + m)/(i*j*1.0);
                if(x - (int)x == 0)
                 count ++;
            }
        }
        cout<<"Case "<<t<<": "<<count<<endl;
    }
    return 0;
}
