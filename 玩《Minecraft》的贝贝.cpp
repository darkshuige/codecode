#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cou.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a, b;
	    cin >> a >> b;
	    int total = a + b;
	    int count = total / 3;
	    if (min(a, b) < count) 
		{
	        count = min(a, b);
	    }
	    cout<< count << endl;	
	}
    return 0;
}