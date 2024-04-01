#include<iostream>
#include<algorithm>
using namespace std;
const int N=200010;
int n,cnt=0;
int a[N];
bool s[N];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) 
	 cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(s[i])
		 continue;
        cnt++;
        for(int j=i+1;j<n;j++)
        {
            if(s[i])
			 continue;
            if(a[j]-a[i]==9)
			{
                s[j]=1;
            }
			else if(a[j]-a[i]>9)
			{
                break;
            }
        }
    }
    cout<<cnt<<endl;
}
