#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char mp[11]={'1','0','X','9','8','7','6','5','4','3','2'};
    char s[18];
    cin>>n;
    int flag3=1;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int flag=1;
        for(int i=0;i<17;i++)
        {
            if(s[i]<'0'||s[i]>'9')
            {
                flag3=0;
                flag=0;
                break;
            }
        }
        int sum=0;
        if(flag==0)
        {
            cout<<s<<endl;
            continue;
        }
        else
        {
            for(int i=0;i<17;i++)
            {
                sum+=(s[i]-'0')*a[i];
                sum%=11;
            }
            
            if(mp[sum]!=s[17])
            {
                flag=0;
                flag3=0;
            }
            if(!flag)
            {
                cout<<s<<endl;
                continue;
            }
        }
    }
    if(flag3)
        cout<<"ALL passed"<<endl;
    return 0;
}
