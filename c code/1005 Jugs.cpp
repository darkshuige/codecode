#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		int x=0,y=0;
		while(y!=c && x!=c)
		{
			if(y==b)
			{
				y=0;
				cout<<"empty B"<<endl;
			}
			if(x==0)
			{
				x=a;
				cout<<"fill A"<<endl;
			}
			else
			{
				if(x+y<b)
				{
					y=x+y;
					x=0;
					cout<<"pour A B"<<endl;
				}
				else
				{
					x=x-(b-y);
					cout<<"pour A B"<<endl;
					y=b;
				}
			}
		}
		cout<<"success"<<endl;
	}
	return 0;
} 
