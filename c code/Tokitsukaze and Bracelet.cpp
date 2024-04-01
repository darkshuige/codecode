#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	int a,b,c;
    	int sum=0;
    	cin>>a>>b>>c;
    	if(a==150) sum++;
		else if(a==200) sum+=2;
		if(b>=34 && b<=40) sum++;
		else if(b==45) sum+=2;
		if(c>=34 && c<=40) sum++;
		else if(c==45) sum+=2;
		cout<<sum<<endl;
	}
    return 0;
}
