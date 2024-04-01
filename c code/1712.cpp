
#include<bits/stdc++.h>
using namespace std; 
int main()
{
    int n,i;
    long int re;
    while(cin>>n)
    {
        if(n==3)
    	 cout<<0<<endl;
        else if(n==4)
         cout<<1<<endl;
        else if(n%2==0)
        {
            int t=n/2;
            re=n*(n-1)*(n-2)*(n-3)/24-t*(t-1)/2+1;
            cout<<re<<endl;
        }
        else
        {
            re=n*(n-1)*(n-2)*(n-3)/24;
            cout<<re<<endl;
        }
    }
    return 0;
}

