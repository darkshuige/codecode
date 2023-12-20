#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n<=100 && n>=90)
		{
			cout<<"A"<<endl;
		}
		else if(n<=89 && n>=80)
		{
			cout<<"B"<<endl;
		}
		else if(n<=79 && n>=70)
		{
			cout<<"C"<<endl;
		}
		else if(n<=69 && n>=60)
		{
			cout<<"D"<<endl;
		}
		else if(n<=59 && n>=0)
		{
			cout<<"E"<<endl;
		}
		else
		{
			cout<<"Score is error!"<<endl;
		}
	}
	return 0;
}
