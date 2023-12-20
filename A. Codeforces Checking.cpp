#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char op;
		cin>>op;
		if(op=='c' || op=='o' || op=='d' || op=='e' || op=='f' || op=='r' || op=='s')
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
    return 0;
}
