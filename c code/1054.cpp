#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,f,a,b,c;
    cin>>n;
    while(n--)
    {
        int sum = 0;
        cin>>f;
        while(f--)
        {
            cin>>a>>b>>c;
            sum+=a*c;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}
