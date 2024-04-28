#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ull unsigned long long
using namespace std;
const int maxn=200;
deque<int>de;
signed main()
{
	jiasu;
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		de.push_back(x);
		while(1)
		{
			if(de.size()<=1) break;
			if(de.size()>=2 && de[de.size()-1]!=de[de.size()-2] ) break;
			if(de.size()>=2 && de[de.size()-1]==de[de.size()-2] )
			{
				int sum=0;
				sum=de.back()+1;
				de.pop_back();
				de.pop_back();
				de.push_back(sum);
			}	
		}
		
	}
	cout<<de.size()<<endl;
	return 0;
}
