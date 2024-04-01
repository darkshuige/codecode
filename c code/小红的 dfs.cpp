#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;
char a[maxn];
char s1[maxn]={'0','0','d','0','d','f','s','0','s','0'};
char s2[maxn]={'0','d','f','s','f','0','0','s','0','0'};
char s3[maxn]={'0','0','0','d','0','0','f','d','f','s'};
signed main()
{
    jiasu;
    for(int i=1;i<=9;i++) cin>>a[i];
    int sum1=0,sum2=0,sum3=0;
    for(int i=1;i<=9;i++)
    {
    	if(s1[i]!='0' && s1[i]!=a[i]) sum1++;
    	if(s2[i]!='0' && s2[i]!=a[i]) sum2++;
    	if(s3[i]!='0' && s3[i]!=a[i]) sum3++;
	}
	cout<<min(sum1,min(sum2,sum3))<<endl;
    return 0;
}
