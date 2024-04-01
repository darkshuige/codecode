#include<bits/stdc++.h>
using namespace std;
int main()
{
	string n;
	while(cin>>n)
	{
		int len=n.size();
		int yu=0;
		for(int i=0;i<len;i++)
		{
			yu=yu*10+(n[i]-48);
			yu%=3;
		}
		if(yu==0)
		 cout<<0<<endl;
		else
		 cout<<1<<endl;
	}		
	return 0;
}
//0 1 2 3 4 5 6 7  8  9  10
//0 1 1 2 3 5 8 13 21 34 55
//0 1 1 0 1 1 0 1  1  0  1
