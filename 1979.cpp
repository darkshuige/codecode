#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int cnt=1,pos=2;
		while(pos!=1)
		{
			cnt++;
			if(pos<=n)
			 pos*=2;
			else
			 pos=(pos-n)*2-1;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
