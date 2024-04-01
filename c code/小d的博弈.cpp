#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        int cnt=0;
        cin>>x>>y;
        if(x==y)
            cout<<"Bob"<<endl;
        else if((x==1&&y==2)||(x==2&&y==1))
            cout<<"Bob"<<endl;
        else if(x==1||y==2||y==1||x==2)
            cout<<"Alice"<<endl;
        else if(x>2*y||y>2*x)
            cout<<"Alice"<<endl;
        else{
            int cnt=0;
            while(1)
            {
                if(x>y)
                {
                    x=x-(x/2+1);
                    cnt++;
                    if(x==1||x==2)
                        break;
                    if(y>2*x)
                        break;
                }
                else
                {
                    y=y-(y/2+1);
                    cnt++;
                    if(y==1||y==2)
                        break;
                    if(x>2*y)
                        break;
                }
            }
            if(cnt%2==1)
                cout<<"Bob"<<endl;
            else
                cout<<"Alice"<<endl;
        }
    }
    return 0;
}
