#include<bits/stdc++.h>
using namespace std;
long long int s[1000010];
int main()
{
    s[0]=1,s[1]=2;
    for(int i=2;i<=1000000;i++)
	{
        s[i]=s[i-1]%2021+s[i-2]%2021;
    }
    int n;
    while(scanf("%d",&n))
	{
        if(n==0)break;
        cout<<s[n]%2021<<endl;
	}
}
