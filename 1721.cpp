#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            if(n%i==0)
             sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
